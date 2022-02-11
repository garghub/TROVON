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
if ( V_9 == '\\' && V_5 & V_16 ) {
if( ! V_7 ( V_1 , L_5 , 2 ) ) return - 1 ;
return 2 ;
}
if( ! V_7 ( V_1 , & V_9 , 1 ) ) return - 1 ;
return 1 ;
}
static int F_7 ( unsigned char * V_2 , int V_17 ,
int type , unsigned char V_5 , char * V_18 , T_1 * V_7 , void * V_1 )
{
int V_19 , V_20 , V_3 ;
unsigned char V_21 , * V_22 , * V_23 ;
unsigned long V_4 ;
V_22 = V_2 ;
V_23 = V_2 + V_17 ;
V_20 = 0 ;
while( V_22 != V_23 ) {
if( V_22 == V_2 && V_5 & V_24 ) V_21 = V_25 ;
else V_21 = 0 ;
switch( type & V_26 ) {
case 4 :
V_4 = ( ( unsigned long ) * V_22 ++ ) << 24 ;
V_4 |= ( ( unsigned long ) * V_22 ++ ) << 16 ;
V_4 |= ( ( unsigned long ) * V_22 ++ ) << 8 ;
V_4 |= * V_22 ++ ;
break;
case 2 :
V_4 = ( ( unsigned long ) * V_22 ++ ) << 8 ;
V_4 |= * V_22 ++ ;
break;
case 1 :
V_4 = * V_22 ++ ;
break;
case 0 :
V_19 = F_8 ( V_22 , V_17 , & V_4 ) ;
if( V_19 < 0 ) return - 1 ;
V_22 += V_19 ;
break;
default:
return - 1 ;
}
if ( V_22 == V_23 && V_5 & V_24 ) V_21 = V_27 ;
if( type & V_28 ) {
unsigned char V_29 [ 6 ] ;
int V_30 ;
V_30 = F_9 ( V_29 , sizeof V_29 , V_4 ) ;
for( V_19 = 0 ; V_19 < V_30 ; V_19 ++ ) {
V_3 = F_4 ( V_29 [ V_19 ] , ( unsigned char ) ( V_5 | V_21 ) , V_18 , V_7 , V_1 ) ;
if( V_3 < 0 ) return - 1 ;
V_20 += V_3 ;
}
} else {
V_3 = F_4 ( V_4 , ( unsigned char ) ( V_5 | V_21 ) , V_18 , V_7 , V_1 ) ;
if( V_3 < 0 ) return - 1 ;
V_20 += V_3 ;
}
}
return V_20 ;
}
static int F_10 ( T_1 * V_7 , void * V_1 , unsigned char * V_2 , int V_17 )
{
static const char V_31 [] = L_6 ;
unsigned char * V_22 , * V_23 ;
char V_32 [ 2 ] ;
if( V_1 ) {
V_22 = V_2 ;
V_23 = V_2 + V_17 ;
while( V_22 != V_23 ) {
V_32 [ 0 ] = V_31 [ * V_22 >> 4 ] ;
V_32 [ 1 ] = V_31 [ * V_22 & 0xf ] ;
if( ! V_7 ( V_1 , V_32 , 2 ) ) return - 1 ;
V_22 ++ ;
}
}
return V_17 << 1 ;
}
static int F_11 ( unsigned long V_33 , T_1 * V_7 , void * V_1 , T_2 * V_34 )
{
T_3 V_35 ;
unsigned char * V_36 , * V_22 ;
int V_20 , V_37 ;
if( ! V_7 ( V_1 , L_7 , 1 ) ) return - 1 ;
if( ! ( V_33 & V_38 ) ) {
V_20 = F_10 ( V_7 , V_1 , V_34 -> V_39 , V_34 -> V_40 ) ;
if( V_20 < 0 ) return - 1 ;
return V_20 + 1 ;
}
V_35 . type = V_34 -> type ;
V_35 . V_41 . V_42 = ( char * ) V_34 ;
V_37 = F_12 ( & V_35 , NULL ) ;
V_36 = F_13 ( V_37 ) ;
if( ! V_36 ) return - 1 ;
V_22 = V_36 ;
F_12 ( & V_35 , & V_22 ) ;
V_20 = F_10 ( V_7 , V_1 , V_36 , V_37 ) ;
F_14 ( V_36 ) ;
if( V_20 < 0 ) return - 1 ;
return V_20 + 1 ;
}
static int F_15 ( T_1 * V_7 , void * V_1 , unsigned long V_33 , T_2 * V_34 )
{
int V_20 , V_3 ;
int type ;
char V_18 ;
unsigned char V_5 ;
V_18 = 0 ;
V_5 = ( unsigned char ) ( V_33 & V_16 ) ;
type = V_34 -> type ;
V_20 = 0 ;
if( V_33 & V_43 ) {
const char * V_44 ;
V_44 = F_16 ( type ) ;
V_20 += strlen ( V_44 ) ;
if( ! V_7 ( V_1 , V_44 , V_20 ) || ! V_7 ( V_1 , L_8 , 1 ) ) return - 1 ;
V_20 ++ ;
}
if( V_33 & V_45 ) type = - 1 ;
else if( V_33 & V_46 ) type = 1 ;
else {
if( ( type > 0 ) && ( type < 31 ) ) type = V_47 [ type ] ;
else type = - 1 ;
if( ( type == - 1 ) && ! ( V_33 & V_48 ) ) type = 1 ;
}
if( type == - 1 ) {
V_3 = F_11 ( V_33 , V_7 , V_1 , V_34 ) ;
if( V_3 < 0 ) return - 1 ;
V_20 += V_3 ;
return V_20 ;
}
if( V_33 & V_49 ) {
if( ! type ) type = 1 ;
else type |= V_28 ;
}
V_3 = F_7 ( V_34 -> V_39 , V_34 -> V_40 , type , V_5 , & V_18 , V_7 , NULL ) ;
if( V_3 < 0 ) return - 1 ;
V_20 += V_3 ;
if( V_18 ) V_20 += 2 ;
if( ! V_1 ) return V_20 ;
if( V_18 && ! V_7 ( V_1 , L_9 , 1 ) ) return - 1 ;
if( F_7 ( V_34 -> V_39 , V_34 -> V_40 , type , V_5 , NULL , V_7 , V_1 ) < 0 )
return - 1 ;
if( V_18 && ! V_7 ( V_1 , L_9 , 1 ) ) return - 1 ;
return V_20 ;
}
static int F_17 ( T_1 * V_7 , void * V_1 , int V_50 )
{
int V_19 ;
for( V_19 = 0 ; V_19 < V_50 ; V_19 ++ )
if( ! V_7 ( V_1 , L_10 , 1 ) ) return 0 ;
return 1 ;
}
static int F_18 ( T_1 * V_7 , void * V_1 , T_4 * V_51 ,
int V_50 , unsigned long V_5 )
{
int V_19 , V_52 = - 1 , V_21 , V_53 ;
int V_54 , V_55 ;
T_5 * V_56 ;
T_2 * V_57 ;
T_6 * V_58 ;
char V_59 [ 80 ] ;
const char * V_60 ;
int V_20 , V_3 ;
char * V_61 , * V_62 , * V_63 ;
int V_64 , V_65 , V_66 ;
if( V_50 < 0 ) V_50 = 0 ;
V_20 = V_50 ;
if( ! F_17 ( V_7 , V_1 , V_50 ) ) return - 1 ;
switch ( V_5 & V_67 )
{
case V_68 :
V_61 = L_11 ;
V_64 = 1 ;
V_62 = L_12 ;
V_65 = 3 ;
break;
case V_69 :
V_61 = L_13 ;
V_64 = 1 ;
V_62 = L_14 ;
V_65 = 1 ;
V_50 = 0 ;
break;
case V_70 :
V_61 = L_15 ;
V_64 = 2 ;
V_62 = L_12 ;
V_65 = 3 ;
V_50 = 0 ;
break;
case V_71 :
V_61 = L_16 ;
V_64 = 2 ;
V_62 = L_12 ;
V_65 = 3 ;
V_50 = 0 ;
break;
default:
return - 1 ;
}
if( V_5 & V_72 ) {
V_63 = L_17 ;
V_66 = 3 ;
} else {
V_63 = L_18 ;
V_66 = 1 ;
}
V_54 = V_5 & V_73 ;
V_53 = F_19 ( V_51 ) ;
for( V_19 = 0 ; V_19 < V_53 ; V_19 ++ ) {
if( V_5 & V_74 )
V_58 = F_20 ( V_51 , V_53 - V_19 - 1 ) ;
else V_58 = F_20 ( V_51 , V_19 ) ;
if( V_52 != - 1 ) {
if( V_52 == V_58 -> V_75 ) {
if( ! V_7 ( V_1 , V_62 , V_65 ) ) return - 1 ;
V_20 += V_65 ;
} else {
if( ! V_7 ( V_1 , V_61 , V_64 ) ) return - 1 ;
V_20 += V_64 ;
if( ! F_17 ( V_7 , V_1 , V_50 ) ) return - 1 ;
V_20 += V_50 ;
}
}
V_52 = V_58 -> V_75 ;
V_56 = F_21 ( V_58 ) ;
V_57 = F_22 ( V_58 ) ;
V_55 = F_23 ( V_56 ) ;
if( V_54 != V_76 ) {
int V_77 , V_78 ;
if( ( V_54 == V_79 ) || ( V_55 == V_80 ) ) {
F_24 ( V_59 , sizeof V_59 , V_56 , 1 ) ;
V_78 = 0 ;
V_60 = V_59 ;
} else {
if( V_54 == V_81 ) {
V_78 = V_82 ;
V_60 = F_25 ( V_55 ) ;
} else if( V_54 == V_83 ) {
V_78 = V_84 ;
V_60 = F_26 ( V_55 ) ;
} else {
V_78 = 0 ;
V_60 = L_19 ;
}
}
V_77 = strlen ( V_60 ) ;
if( ! V_7 ( V_1 , V_60 , V_77 ) ) return - 1 ;
if ( ( V_77 < V_78 ) && ( V_5 & V_85 ) ) {
if ( ! F_17 ( V_7 , V_1 , V_78 - V_77 ) ) return - 1 ;
V_20 += V_78 - V_77 ;
}
if( ! V_7 ( V_1 , V_63 , V_66 ) ) return - 1 ;
V_20 += V_77 + V_66 ;
}
if( ( V_55 == V_80 ) && ( V_5 & V_86 ) )
V_21 = V_45 ;
else V_21 = 0 ;
V_3 = F_15 ( V_7 , V_1 , V_5 | V_21 , V_57 ) ;
if( V_3 < 0 ) return - 1 ;
V_20 += V_3 ;
}
return V_20 ;
}
int F_27 ( T_7 * V_87 , T_4 * V_88 , int V_50 , unsigned long V_5 )
{
if( V_5 == V_89 )
return F_28 ( V_87 , V_88 , V_50 ) ;
return F_18 ( F_1 , V_87 , V_88 , V_50 , V_5 ) ;
}
int F_29 ( T_8 * V_90 , T_4 * V_88 , int V_50 , unsigned long V_5 )
{
if( V_5 == V_89 )
{
T_7 * V_91 ;
int V_92 ;
V_91 = F_30 ( V_90 , V_93 ) ;
if( ! V_91 ) return - 1 ;
V_92 = F_28 ( V_91 , V_88 , V_50 ) ;
F_31 ( V_91 ) ;
return V_92 ;
}
return F_18 ( F_3 , V_90 , V_88 , V_50 , V_5 ) ;
}
int F_32 ( T_7 * V_87 , T_2 * V_34 , unsigned long V_5 )
{
return F_15 ( F_1 , V_87 , V_5 , V_34 ) ;
}
int F_33 ( T_8 * V_90 , T_2 * V_34 , unsigned long V_5 )
{
return F_15 ( F_3 , V_90 , V_5 , V_34 ) ;
}
int F_34 ( unsigned char * * V_87 , T_2 * V_94 )
{
T_2 V_95 , * V_34 = & V_95 ;
int V_96 , type , V_92 ;
if( ! V_94 ) return - 1 ;
type = V_94 -> type ;
if( ( type < 0 ) || ( type > 30 ) ) return - 1 ;
V_96 = V_47 [ type ] ;
if( V_96 == - 1 ) return - 1 ;
V_96 |= V_97 ;
V_95 . V_39 = NULL ;
V_92 = F_35 ( & V_34 , V_94 -> V_39 , V_94 -> V_40 , V_96 , V_98 ) ;
if( V_92 < 0 ) return V_92 ;
* V_87 = V_95 . V_39 ;
return V_95 . V_40 ;
}
