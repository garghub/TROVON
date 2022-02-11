static int F_1 ( void * V_1 , const void * V_2 , int V_3 )
{
if( ! V_1 ) return 1 ;
if( F_2 ( V_1 , V_2 , V_3 ) != V_3 ) return 0 ;
return 1 ;
}
static int F_3 ( void * V_1 , const void * V_2 , int V_3 )
{
if( ! V_1 ) return 1 ;
if( fwrite ( V_2 , 1 , V_3 , V_1 ) != ( unsigned int ) V_3 ) return 0 ;
return 1 ;
}
static int F_4 ( unsigned long V_4 , unsigned char V_5 , char * V_6 , T_1 * V_7 , void * V_1 )
{
unsigned char V_8 , V_9 ;
char V_10 [ F_5 ( long ) + 3 ] ;
if( V_4 > 0xffffffffL )
return - 1 ;
if( V_4 > 0xffff ) {
F_6 ( V_10 , sizeof V_10 , L_1 , V_4 ) ;
if( ! V_7 ( V_1 , V_10 , 10 ) ) return - 1 ;
return 10 ;
}
if( V_4 > 0xff ) {
F_6 ( V_10 , sizeof V_10 , L_2 , V_4 ) ;
if( ! V_7 ( V_1 , V_10 , 6 ) ) return - 1 ;
return 6 ;
}
V_9 = ( unsigned char ) V_4 ;
if( V_9 > 0x7f ) V_8 = V_5 & V_11 ;
else V_8 = V_12 [ V_9 ] & V_5 ;
if( V_8 & V_13 ) {
if( V_8 & V_14 ) {
if( V_6 ) * V_6 = 1 ;
if( ! V_7 ( V_1 , & V_9 , 1 ) ) return - 1 ;
return 1 ;
}
if( ! V_7 ( V_1 , L_3 , 1 ) ) return - 1 ;
if( ! V_7 ( V_1 , & V_9 , 1 ) ) return - 1 ;
return 2 ;
}
if( V_8 & ( V_15 | V_11 ) ) {
F_6 ( V_10 , 11 , L_4 , V_9 ) ;
if( ! V_7 ( V_1 , V_10 , 3 ) ) return - 1 ;
return 3 ;
}
if( ! V_7 ( V_1 , & V_9 , 1 ) ) return - 1 ;
return 1 ;
}
static int F_7 ( unsigned char * V_2 , int V_16 ,
int type , unsigned char V_5 , char * V_17 , T_1 * V_7 , void * V_1 )
{
int V_18 , V_19 , V_3 ;
unsigned char V_20 , * V_21 , * V_22 ;
unsigned long V_4 ;
V_21 = V_2 ;
V_22 = V_2 + V_16 ;
V_19 = 0 ;
while( V_21 != V_22 ) {
if( V_21 == V_2 ) V_20 = V_23 ;
else V_20 = 0 ;
switch( type & V_24 ) {
case 4 :
V_4 = ( ( unsigned long ) * V_21 ++ ) << 24 ;
V_4 |= ( ( unsigned long ) * V_21 ++ ) << 16 ;
V_4 |= ( ( unsigned long ) * V_21 ++ ) << 8 ;
V_4 |= * V_21 ++ ;
break;
case 2 :
V_4 = ( ( unsigned long ) * V_21 ++ ) << 8 ;
V_4 |= * V_21 ++ ;
break;
case 1 :
V_4 = * V_21 ++ ;
break;
case 0 :
V_18 = F_8 ( V_21 , V_16 , & V_4 ) ;
if( V_18 < 0 ) return - 1 ;
V_21 += V_18 ;
break;
}
if ( V_21 == V_22 ) V_20 = V_25 ;
if( type & V_26 ) {
unsigned char V_27 [ 6 ] ;
int V_28 ;
V_28 = F_9 ( V_27 , sizeof V_27 , V_4 ) ;
for( V_18 = 0 ; V_18 < V_28 ; V_18 ++ ) {
V_3 = F_4 ( V_27 [ V_18 ] , ( unsigned char ) ( V_5 | V_20 ) , V_17 , V_7 , V_1 ) ;
if( V_3 < 0 ) return - 1 ;
V_19 += V_3 ;
}
} else {
V_3 = F_4 ( V_4 , ( unsigned char ) ( V_5 | V_20 ) , V_17 , V_7 , V_1 ) ;
if( V_3 < 0 ) return - 1 ;
V_19 += V_3 ;
}
}
return V_19 ;
}
static int F_10 ( T_1 * V_7 , void * V_1 , unsigned char * V_2 , int V_16 )
{
const static char V_29 [] = L_5 ;
unsigned char * V_21 , * V_22 ;
char V_30 [ 2 ] ;
if( V_1 ) {
V_21 = V_2 ;
V_22 = V_2 + V_16 ;
while( V_21 != V_22 ) {
V_30 [ 0 ] = V_29 [ * V_21 >> 4 ] ;
V_30 [ 1 ] = V_29 [ * V_21 & 0xf ] ;
if( ! V_7 ( V_1 , V_30 , 2 ) ) return - 1 ;
V_21 ++ ;
}
}
return V_16 << 1 ;
}
static int F_11 ( unsigned long V_31 , T_1 * V_7 , void * V_1 , T_2 * V_32 )
{
T_3 V_33 ;
unsigned char * V_34 , * V_21 ;
int V_19 , V_35 ;
if( ! V_7 ( V_1 , L_6 , 1 ) ) return - 1 ;
if( ! ( V_31 & V_36 ) ) {
V_19 = F_10 ( V_7 , V_1 , V_32 -> V_37 , V_32 -> V_38 ) ;
if( V_19 < 0 ) return - 1 ;
return V_19 + 1 ;
}
V_33 . type = V_32 -> type ;
V_33 . V_39 . V_40 = ( char * ) V_32 ;
V_35 = F_12 ( & V_33 , NULL ) ;
V_34 = F_13 ( V_35 ) ;
if( ! V_34 ) return - 1 ;
V_21 = V_34 ;
F_12 ( & V_33 , & V_21 ) ;
V_19 = F_10 ( V_7 , V_1 , V_34 , V_35 ) ;
F_14 ( V_34 ) ;
if( V_19 < 0 ) return - 1 ;
return V_19 + 1 ;
}
static int F_15 ( T_1 * V_7 , void * V_1 , unsigned long V_31 , T_2 * V_32 )
{
int V_19 , V_3 ;
int type ;
char V_17 ;
unsigned char V_5 ;
V_17 = 0 ;
V_5 = ( unsigned char ) ( V_31 & V_41 ) ;
type = V_32 -> type ;
V_19 = 0 ;
if( V_31 & V_42 ) {
const char * V_43 ;
V_43 = F_16 ( type ) ;
V_19 += strlen ( V_43 ) ;
if( ! V_7 ( V_1 , V_43 , V_19 ) || ! V_7 ( V_1 , L_7 , 1 ) ) return - 1 ;
V_19 ++ ;
}
if( V_31 & V_44 ) type = - 1 ;
else if( V_31 & V_45 ) type = 1 ;
else {
if( ( type > 0 ) && ( type < 31 ) ) type = V_46 [ type ] ;
else type = - 1 ;
if( ( type == - 1 ) && ! ( V_31 & V_47 ) ) type = 1 ;
}
if( type == - 1 ) {
V_3 = F_11 ( V_31 , V_7 , V_1 , V_32 ) ;
if( V_3 < 0 ) return - 1 ;
V_19 += V_3 ;
return V_19 ;
}
if( V_31 & V_48 ) {
if( ! type ) type = 1 ;
else type |= V_26 ;
}
V_3 = F_7 ( V_32 -> V_37 , V_32 -> V_38 , type , V_5 , & V_17 , V_7 , NULL ) ;
if( V_19 < 0 ) return - 1 ;
V_19 += V_3 ;
if( V_17 ) V_19 += 2 ;
if( ! V_1 ) return V_19 ;
if( V_17 && ! V_7 ( V_1 , L_8 , 1 ) ) return - 1 ;
F_7 ( V_32 -> V_37 , V_32 -> V_38 , type , V_5 , NULL , V_7 , V_1 ) ;
if( V_17 && ! V_7 ( V_1 , L_8 , 1 ) ) return - 1 ;
return V_19 ;
}
static int F_17 ( T_1 * V_7 , void * V_1 , int V_49 )
{
int V_18 ;
for( V_18 = 0 ; V_18 < V_49 ; V_18 ++ )
if( ! V_7 ( V_1 , L_9 , 1 ) ) return 0 ;
return 1 ;
}
static int F_18 ( T_1 * V_7 , void * V_1 , T_4 * V_50 ,
int V_49 , unsigned long V_5 )
{
int V_18 , V_51 = - 1 , V_20 , V_52 ;
int V_53 , V_54 ;
T_5 * V_55 ;
T_2 * V_56 ;
T_6 * V_57 ;
char V_58 [ 80 ] ;
const char * V_59 ;
int V_19 , V_3 ;
char * V_60 , * V_61 , * V_62 ;
int V_63 , V_64 , V_65 ;
if( V_49 < 0 ) V_49 = 0 ;
V_19 = V_49 ;
if( ! F_17 ( V_7 , V_1 , V_49 ) ) return - 1 ;
switch ( V_5 & V_66 )
{
case V_67 :
V_60 = L_10 ;
V_63 = 1 ;
V_61 = L_11 ;
V_64 = 3 ;
break;
case V_68 :
V_60 = L_12 ;
V_63 = 1 ;
V_61 = L_13 ;
V_64 = 1 ;
V_49 = 0 ;
break;
case V_69 :
V_60 = L_14 ;
V_63 = 2 ;
V_61 = L_11 ;
V_64 = 3 ;
V_49 = 0 ;
break;
case V_70 :
V_60 = L_15 ;
V_63 = 2 ;
V_61 = L_11 ;
V_64 = 3 ;
V_49 = 0 ;
break;
default:
return - 1 ;
}
if( V_5 & V_71 ) {
V_62 = L_16 ;
V_65 = 3 ;
} else {
V_62 = L_17 ;
V_65 = 1 ;
}
V_53 = V_5 & V_72 ;
V_52 = F_19 ( V_50 ) ;
for( V_18 = 0 ; V_18 < V_52 ; V_18 ++ ) {
if( V_5 & V_73 )
V_57 = F_20 ( V_50 , V_52 - V_18 - 1 ) ;
else V_57 = F_20 ( V_50 , V_18 ) ;
if( V_51 != - 1 ) {
if( V_51 == V_57 -> V_74 ) {
if( ! V_7 ( V_1 , V_61 , V_64 ) ) return - 1 ;
V_19 += V_64 ;
} else {
if( ! V_7 ( V_1 , V_60 , V_63 ) ) return - 1 ;
V_19 += V_63 ;
if( ! F_17 ( V_7 , V_1 , V_49 ) ) return - 1 ;
V_19 += V_49 ;
}
}
V_51 = V_57 -> V_74 ;
V_55 = F_21 ( V_57 ) ;
V_56 = F_22 ( V_57 ) ;
V_54 = F_23 ( V_55 ) ;
if( V_53 != V_75 ) {
int V_76 , V_77 ;
if( ( V_53 == V_78 ) || ( V_54 == V_79 ) ) {
F_24 ( V_58 , sizeof V_58 , V_55 , 1 ) ;
V_77 = 0 ;
V_59 = V_58 ;
} else {
if( V_53 == V_80 ) {
V_77 = V_81 ;
V_59 = F_25 ( V_54 ) ;
} else if( V_53 == V_82 ) {
V_77 = V_83 ;
V_59 = F_26 ( V_54 ) ;
} else {
V_77 = 0 ;
V_59 = L_18 ;
}
}
V_76 = strlen ( V_59 ) ;
if( ! V_7 ( V_1 , V_59 , V_76 ) ) return - 1 ;
if ( ( V_76 < V_77 ) && ( V_5 & V_84 ) ) {
if ( ! F_17 ( V_7 , V_1 , V_77 - V_76 ) ) return - 1 ;
V_19 += V_77 - V_76 ;
}
if( ! V_7 ( V_1 , V_62 , V_65 ) ) return - 1 ;
V_19 += V_76 + V_65 ;
}
if( ( V_54 == V_79 ) && ( V_5 & V_85 ) )
V_20 = V_44 ;
else V_20 = 0 ;
V_3 = F_15 ( V_7 , V_1 , V_5 | V_20 , V_56 ) ;
if( V_3 < 0 ) return - 1 ;
V_19 += V_3 ;
}
return V_19 ;
}
int F_27 ( T_7 * V_86 , T_4 * V_87 , int V_49 , unsigned long V_5 )
{
if( V_5 == V_88 )
return F_28 ( V_86 , V_87 , V_49 ) ;
return F_18 ( F_1 , V_86 , V_87 , V_49 , V_5 ) ;
}
int F_29 ( T_8 * V_89 , T_4 * V_87 , int V_49 , unsigned long V_5 )
{
if( V_5 == V_88 )
{
T_7 * V_90 ;
int V_91 ;
V_90 = F_30 ( V_89 , V_92 ) ;
if( ! V_90 ) return - 1 ;
V_91 = F_28 ( V_90 , V_87 , V_49 ) ;
F_31 ( V_90 ) ;
return V_91 ;
}
return F_18 ( F_3 , V_89 , V_87 , V_49 , V_5 ) ;
}
int F_32 ( T_7 * V_86 , T_2 * V_32 , unsigned long V_5 )
{
return F_15 ( F_1 , V_86 , V_5 , V_32 ) ;
}
int F_33 ( T_8 * V_89 , T_2 * V_32 , unsigned long V_5 )
{
return F_15 ( F_3 , V_89 , V_5 , V_32 ) ;
}
int F_34 ( unsigned char * * V_86 , T_2 * V_93 )
{
T_2 V_94 , * V_32 = & V_94 ;
int V_95 , type , V_91 ;
if( ! V_93 ) return - 1 ;
type = V_93 -> type ;
if( ( type < 0 ) || ( type > 30 ) ) return - 1 ;
V_95 = V_46 [ type ] ;
if( V_95 == - 1 ) return - 1 ;
V_95 |= V_96 ;
V_94 . V_37 = NULL ;
V_91 = F_35 ( & V_32 , V_93 -> V_37 , V_93 -> V_38 , V_95 , V_97 ) ;
if( V_91 < 0 ) return V_91 ;
* V_86 = V_94 . V_37 ;
return V_94 . V_38 ;
}
