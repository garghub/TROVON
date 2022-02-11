int F_1 ( void * V_1 , const void * V_2 , int V_3 )
{
unsigned char * * V_4 = V_1 ;
if( ! V_4 ) return 1 ;
memcpy ( * V_4 , V_2 , V_3 ) ;
* V_4 += V_3 ;
return 1 ;
}
int F_2 ( void * V_1 , const void * V_2 , int V_3 )
{
if( ! V_1 ) return 1 ;
if( F_3 ( V_1 , V_2 , V_3 ) != V_3 ) return 0 ;
return 1 ;
}
int F_4 ( void * V_1 , const void * V_2 , int V_3 )
{
if( ! V_1 ) return 1 ;
if( fwrite ( V_2 , 1 , V_3 , V_1 ) != ( unsigned int ) V_3 ) return 0 ;
return 1 ;
}
static int F_5 ( unsigned long V_5 , unsigned char V_6 , char * V_7 , T_1 * V_8 , void * V_1 )
{
unsigned char V_9 , V_10 ;
char V_11 [ 11 ] ;
if( V_5 > 0xffff ) {
F_6 ( V_11 , 11 , L_1 , V_5 ) ;
if( ! V_8 ( V_1 , V_11 , 10 ) ) return - 1 ;
return 10 ;
}
if( V_5 > 0xff ) {
F_6 ( V_11 , 11 , L_2 , V_5 ) ;
if( ! V_8 ( V_1 , V_11 , 6 ) ) return - 1 ;
return 6 ;
}
V_10 = ( unsigned char ) V_5 ;
if( V_10 > 0x7f ) V_9 = V_6 & V_12 ;
else V_9 = V_13 [ V_10 ] & V_6 ;
if( V_9 & V_14 ) {
if( V_9 & V_15 ) {
if( V_7 ) * V_7 = 1 ;
if( ! V_8 ( V_1 , & V_10 , 1 ) ) return - 1 ;
return 1 ;
}
if( ! V_8 ( V_1 , L_3 , 1 ) ) return - 1 ;
if( ! V_8 ( V_1 , & V_10 , 1 ) ) return - 1 ;
return 2 ;
}
if( V_9 & ( V_16 | V_12 ) ) {
F_6 ( V_11 , 11 , L_4 , V_10 ) ;
if( ! V_8 ( V_1 , V_11 , 3 ) ) return - 1 ;
return 3 ;
}
if( ! V_8 ( V_1 , & V_10 , 1 ) ) return - 1 ;
return 1 ;
}
static int F_7 ( unsigned char * V_2 , int V_17 ,
int type , unsigned char V_6 , char * V_18 , T_1 * V_8 , void * V_1 )
{
int V_19 , V_20 , V_3 ;
unsigned char V_21 , * V_22 , * V_23 ;
unsigned long V_5 ;
V_22 = V_2 ;
V_23 = V_2 + V_17 ;
V_20 = 0 ;
while( V_22 != V_23 ) {
if( V_22 == V_2 ) V_21 = V_24 ;
else V_21 = 0 ;
switch( type & V_25 ) {
case 4 :
V_5 = ( ( unsigned long ) * V_22 ++ ) << 24 ;
V_5 |= ( ( unsigned long ) * V_22 ++ ) << 16 ;
V_5 |= ( ( unsigned long ) * V_22 ++ ) << 8 ;
V_5 |= * V_22 ++ ;
break;
case 2 :
V_5 = ( ( unsigned long ) * V_22 ++ ) << 8 ;
V_5 |= * V_22 ++ ;
break;
case 1 :
V_5 = * V_22 ++ ;
break;
case 0 :
V_19 = F_8 ( V_22 , V_17 , & V_5 ) ;
if( V_19 < 0 ) return - 1 ;
V_22 += V_19 ;
break;
}
if ( V_22 == V_23 ) V_21 = V_26 ;
if( type & V_27 ) {
unsigned char V_28 [ 6 ] ;
int V_29 ;
V_29 = F_9 ( V_28 , 6 , V_5 ) ;
for( V_19 = 0 ; V_19 < V_29 ; V_19 ++ ) {
V_3 = F_5 ( V_28 [ V_19 ] , ( unsigned char ) ( V_6 | V_21 ) , V_18 , V_8 , V_1 ) ;
if( V_3 < 0 ) return - 1 ;
V_20 += V_3 ;
}
} else {
V_3 = F_5 ( V_5 , ( unsigned char ) ( V_6 | V_21 ) , V_18 , V_8 , V_1 ) ;
if( V_3 < 0 ) return - 1 ;
V_20 += V_3 ;
}
}
return V_20 ;
}
static int F_10 ( T_1 * V_8 , void * V_1 , unsigned char * V_2 , int V_17 )
{
const static char V_30 [] = L_5 ;
unsigned char * V_22 , * V_23 ;
char V_31 [ 2 ] ;
if( V_1 ) {
V_22 = V_2 ;
V_23 = V_2 + V_17 ;
while( V_22 != V_23 ) {
V_31 [ 0 ] = V_30 [ * V_22 >> 4 ] ;
V_31 [ 1 ] = V_30 [ * V_22 & 0xf ] ;
if( ! V_8 ( V_1 , V_31 , 2 ) ) return - 1 ;
V_22 ++ ;
}
}
return V_17 << 1 ;
}
int F_11 ( unsigned long V_32 , T_1 * V_8 , void * V_1 , T_2 * V_33 )
{
T_3 V_34 ;
unsigned char * V_35 , * V_22 ;
int V_20 , V_36 ;
if( ! V_8 ( V_1 , L_6 , 1 ) ) return - 1 ;
if( ! ( V_32 & V_37 ) ) {
V_20 = F_10 ( V_8 , V_1 , V_33 -> V_38 , V_33 -> V_39 ) ;
if( V_20 < 0 ) return - 1 ;
return V_20 + 1 ;
}
V_34 . type = V_33 -> type ;
V_34 . V_40 . V_41 = ( char * ) V_33 ;
V_36 = F_12 ( & V_34 , NULL ) ;
V_35 = F_13 ( V_36 ) ;
if( ! V_35 ) return - 1 ;
V_22 = V_35 ;
F_12 ( & V_34 , & V_22 ) ;
V_20 = F_10 ( V_8 , V_1 , V_35 , V_36 ) ;
F_14 ( V_35 ) ;
if( V_20 < 0 ) return - 1 ;
return V_20 + 1 ;
}
static int F_15 ( T_1 * V_8 , void * V_1 , unsigned long V_32 , T_2 * V_33 )
{
int V_20 , V_3 ;
int type ;
char V_18 ;
unsigned char V_6 ;
V_18 = 0 ;
V_6 = ( unsigned char ) ( V_32 & V_42 ) ;
type = V_33 -> type ;
V_20 = 0 ;
if( V_32 & V_43 ) {
const char * V_44 ;
V_44 = F_16 ( type ) ;
V_20 += strlen ( V_44 ) ;
if( ! V_8 ( V_1 , V_44 , V_20 ) || ! V_8 ( V_1 , L_7 , 1 ) ) return - 1 ;
V_20 ++ ;
}
if( V_32 & V_45 ) type = - 1 ;
else if( V_32 & V_46 ) type = 1 ;
else {
if( ( type > 0 ) && ( type < 31 ) ) type = V_47 [ type ] ;
else type = - 1 ;
if( ( type == - 1 ) && ! ( V_32 & V_48 ) ) type = 1 ;
}
if( type == - 1 ) {
V_3 = F_11 ( V_32 , V_8 , V_1 , V_33 ) ;
if( V_3 < 0 ) return - 1 ;
V_20 += V_3 ;
return V_20 ;
}
if( V_32 & V_49 ) {
if( ! type ) type = 1 ;
else type |= V_27 ;
}
V_3 = F_7 ( V_33 -> V_38 , V_33 -> V_39 , type , V_6 , & V_18 , V_8 , NULL ) ;
if( V_20 < 0 ) return - 1 ;
V_20 += V_3 ;
if( V_18 ) V_20 += 2 ;
if( ! V_1 ) return V_20 ;
if( V_18 && ! V_8 ( V_1 , L_8 , 1 ) ) return - 1 ;
F_7 ( V_33 -> V_38 , V_33 -> V_39 , type , V_6 , NULL , V_8 , V_1 ) ;
if( V_18 && ! V_8 ( V_1 , L_8 , 1 ) ) return - 1 ;
return V_20 ;
}
static int F_17 ( T_1 * V_8 , void * V_1 , int V_50 )
{
int V_19 ;
for( V_19 = 0 ; V_19 < V_50 ; V_19 ++ )
if( ! V_8 ( V_1 , L_9 , 1 ) ) return 0 ;
return 1 ;
}
static int F_18 ( T_1 * V_8 , void * V_1 , T_4 * V_51 ,
int V_50 , unsigned long V_6 )
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
if( ! F_17 ( V_8 , V_1 , V_50 ) ) return - 1 ;
switch ( V_6 & V_67 )
{
case V_68 :
V_61 = L_10 ;
V_64 = 1 ;
V_62 = L_11 ;
V_65 = 3 ;
break;
case V_69 :
V_61 = L_12 ;
V_64 = 1 ;
V_62 = L_13 ;
V_65 = 1 ;
V_50 = 0 ;
break;
case V_70 :
V_61 = L_14 ;
V_64 = 2 ;
V_62 = L_11 ;
V_65 = 3 ;
V_50 = 0 ;
break;
case V_71 :
V_61 = L_15 ;
V_64 = 2 ;
V_62 = L_11 ;
V_65 = 3 ;
V_50 = 0 ;
break;
default:
return - 1 ;
}
if( V_6 & V_72 ) {
V_63 = L_16 ;
V_66 = 3 ;
} else {
V_63 = L_17 ;
V_66 = 1 ;
}
V_54 = V_6 & V_73 ;
V_53 = F_19 ( V_51 ) ;
for( V_19 = 0 ; V_19 < V_53 ; V_19 ++ ) {
if( V_6 & V_74 )
V_58 = F_20 ( V_51 , V_53 - V_19 - 1 ) ;
else V_58 = F_20 ( V_51 , V_19 ) ;
if( V_52 != - 1 ) {
if( V_52 == V_58 -> V_75 ) {
if( ! V_8 ( V_1 , V_62 , V_65 ) ) return - 1 ;
V_20 += V_65 ;
} else {
if( ! V_8 ( V_1 , V_61 , V_64 ) ) return - 1 ;
V_20 += V_64 ;
if( ! F_17 ( V_8 , V_1 , V_50 ) ) return - 1 ;
V_20 += V_50 ;
}
}
V_52 = V_58 -> V_75 ;
V_56 = F_21 ( V_58 ) ;
V_57 = F_22 ( V_58 ) ;
V_55 = F_23 ( V_56 ) ;
if( V_54 != V_76 ) {
int V_77 ;
if( ( V_54 == V_78 ) || ( V_55 == V_79 ) ) {
F_24 ( V_59 , 80 , V_56 , 1 ) ;
V_60 = V_59 ;
} else {
if( V_54 == V_80 )
V_60 = F_25 ( V_55 ) ;
else if( V_54 == V_81 )
V_60 = F_26 ( V_55 ) ;
else V_60 = L_18 ;
}
V_77 = strlen ( V_60 ) ;
if( ! V_8 ( V_1 , V_60 , V_77 ) ) return - 1 ;
if( ! V_8 ( V_1 , V_63 , V_66 ) ) return - 1 ;
V_20 += V_77 + V_66 ;
}
if( ( V_55 == V_79 ) && ( V_6 & V_82 ) )
V_21 = V_45 ;
else V_21 = 0 ;
V_3 = F_15 ( V_8 , V_1 , V_6 | V_21 , V_57 ) ;
if( V_3 < 0 ) return - 1 ;
V_20 += V_3 ;
}
return V_20 ;
}
int F_27 ( T_7 * V_4 , T_4 * V_83 , int V_50 , unsigned long V_6 )
{
return F_18 ( F_2 , V_4 , V_83 , V_50 , V_6 ) ;
}
int F_28 ( T_8 * V_84 , T_4 * V_83 , int V_50 , unsigned long V_6 )
{
return F_18 ( F_4 , V_84 , V_83 , V_50 , V_6 ) ;
}
int F_29 ( T_7 * V_4 , T_2 * V_33 , unsigned long V_6 )
{
return F_15 ( F_2 , V_4 , V_6 , V_33 ) ;
}
int F_30 ( T_8 * V_84 , T_2 * V_33 , unsigned long V_6 )
{
return F_15 ( F_4 , V_84 , V_6 , V_33 ) ;
}
int F_31 ( unsigned char * * V_4 , T_2 * V_85 )
{
T_2 V_86 , * V_33 = & V_86 ;
int V_87 , type , V_88 ;
if( ! * V_4 || ! V_85 ) return - 1 ;
type = V_85 -> type ;
if( ( type < 0 ) || ( type > 30 ) ) return - 1 ;
V_87 = V_47 [ type ] ;
if( V_87 == - 1 ) return - 1 ;
V_87 |= V_89 ;
V_86 . V_38 = NULL ;
V_88 = F_32 ( & V_33 , V_85 -> V_38 , V_85 -> V_39 , V_87 , V_90 ) ;
if( V_88 < 0 ) return V_88 ;
if( V_4 ) * V_4 = V_86 . V_38 ;
return V_86 . V_39 ;
}
