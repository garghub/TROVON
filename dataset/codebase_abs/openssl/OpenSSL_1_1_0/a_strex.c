static int F_1 ( void * V_1 , const void * V_2 , int V_3 )
{
if ( ! V_1 )
return 1 ;
if ( F_2 ( V_1 , V_2 , V_3 ) != V_3 )
return 0 ;
return 1 ;
}
static int F_3 ( void * V_1 , const void * V_2 , int V_3 )
{
if ( ! V_1 )
return 1 ;
if ( fwrite ( V_2 , 1 , V_3 , V_1 ) != ( unsigned int ) V_3 )
return 0 ;
return 1 ;
}
static int F_4 ( unsigned long V_4 , unsigned char V_5 , char * V_6 ,
T_1 * V_7 , void * V_1 )
{
unsigned short V_8 ;
unsigned char V_9 ;
char V_10 [ F_5 ( long ) + 3 ] ;
if ( V_4 > 0xffffffffL )
return - 1 ;
if ( V_4 > 0xffff ) {
F_6 ( V_10 , sizeof V_10 , L_1 , V_4 ) ;
if ( ! V_7 ( V_1 , V_10 , 10 ) )
return - 1 ;
return 10 ;
}
if ( V_4 > 0xff ) {
F_6 ( V_10 , sizeof V_10 , L_2 , V_4 ) ;
if ( ! V_7 ( V_1 , V_10 , 6 ) )
return - 1 ;
return 6 ;
}
V_9 = ( unsigned char ) V_4 ;
if ( V_9 > 0x7f )
V_8 = V_5 & V_11 ;
else
V_8 = V_12 [ V_9 ] & V_5 ;
if ( V_8 & V_13 ) {
if ( V_8 & V_14 ) {
if ( V_6 )
* V_6 = 1 ;
if ( ! V_7 ( V_1 , & V_9 , 1 ) )
return - 1 ;
return 1 ;
}
if ( ! V_7 ( V_1 , L_3 , 1 ) )
return - 1 ;
if ( ! V_7 ( V_1 , & V_9 , 1 ) )
return - 1 ;
return 2 ;
}
if ( V_8 & ( V_15
| V_11
| V_16 ) ) {
F_6 ( V_10 , 11 , L_4 , V_9 ) ;
if ( ! V_7 ( V_1 , V_10 , 3 ) )
return - 1 ;
return 3 ;
}
if ( V_9 == '\\' && V_5 & V_17 ) {
if ( ! V_7 ( V_1 , L_5 , 2 ) )
return - 1 ;
return 2 ;
}
if ( ! V_7 ( V_1 , & V_9 , 1 ) )
return - 1 ;
return 1 ;
}
static int F_7 ( unsigned char * V_2 , int V_18 ,
int type , unsigned short V_5 , char * V_19 , T_1 * V_7 ,
void * V_1 )
{
int V_20 , V_21 , V_3 ;
unsigned short V_22 ;
unsigned char * V_23 , * V_24 ;
unsigned long V_4 ;
V_23 = V_2 ;
V_24 = V_2 + V_18 ;
V_21 = 0 ;
while ( V_23 != V_24 ) {
if ( V_23 == V_2 && V_5 & V_25 )
V_22 = V_26 ;
else
V_22 = 0 ;
switch ( type & V_27 ) {
case 4 :
V_4 = ( ( unsigned long ) * V_23 ++ ) << 24 ;
V_4 |= ( ( unsigned long ) * V_23 ++ ) << 16 ;
V_4 |= ( ( unsigned long ) * V_23 ++ ) << 8 ;
V_4 |= * V_23 ++ ;
break;
case 2 :
V_4 = ( ( unsigned long ) * V_23 ++ ) << 8 ;
V_4 |= * V_23 ++ ;
break;
case 1 :
V_4 = * V_23 ++ ;
break;
case 0 :
V_20 = F_8 ( V_23 , V_18 , & V_4 ) ;
if ( V_20 < 0 )
return - 1 ;
V_23 += V_20 ;
break;
default:
return - 1 ;
}
if ( V_23 == V_24 && V_5 & V_25 )
V_22 = V_28 ;
if ( type & V_29 ) {
unsigned char V_30 [ 6 ] ;
int V_31 ;
V_31 = F_9 ( V_30 , sizeof V_30 , V_4 ) ;
for ( V_20 = 0 ; V_20 < V_31 ; V_20 ++ ) {
V_3 =
F_4 ( V_30 [ V_20 ] , ( unsigned short ) ( V_5 | V_22 ) ,
V_19 , V_7 , V_1 ) ;
if ( V_3 < 0 )
return - 1 ;
V_21 += V_3 ;
}
} else {
V_3 =
F_4 ( V_4 , ( unsigned short ) ( V_5 | V_22 ) , V_19 ,
V_7 , V_1 ) ;
if ( V_3 < 0 )
return - 1 ;
V_21 += V_3 ;
}
}
return V_21 ;
}
static int F_10 ( T_1 * V_7 , void * V_1 , unsigned char * V_2 ,
int V_18 )
{
static const char V_32 [] = L_6 ;
unsigned char * V_23 , * V_24 ;
char V_33 [ 2 ] ;
if ( V_1 ) {
V_23 = V_2 ;
V_24 = V_2 + V_18 ;
while ( V_23 != V_24 ) {
V_33 [ 0 ] = V_32 [ * V_23 >> 4 ] ;
V_33 [ 1 ] = V_32 [ * V_23 & 0xf ] ;
if ( ! V_7 ( V_1 , V_33 , 2 ) )
return - 1 ;
V_23 ++ ;
}
}
return V_18 << 1 ;
}
static int F_11 ( unsigned long V_34 , T_1 * V_7 , void * V_1 ,
const T_2 * V_35 )
{
T_3 V_36 ;
unsigned char * V_37 , * V_23 ;
int V_21 , V_38 ;
if ( ! V_7 ( V_1 , L_7 , 1 ) )
return - 1 ;
if ( ! ( V_34 & V_39 ) ) {
V_21 = F_10 ( V_7 , V_1 , V_35 -> V_40 , V_35 -> V_41 ) ;
if ( V_21 < 0 )
return - 1 ;
return V_21 + 1 ;
}
V_36 . type = V_35 -> type ;
V_36 . V_42 . V_43 = ( char * ) V_35 ;
V_38 = F_12 ( & V_36 , NULL ) ;
V_37 = F_13 ( V_38 ) ;
if ( V_37 == NULL )
return - 1 ;
V_23 = V_37 ;
F_12 ( & V_36 , & V_23 ) ;
V_21 = F_10 ( V_7 , V_1 , V_37 , V_38 ) ;
F_14 ( V_37 ) ;
if ( V_21 < 0 )
return - 1 ;
return V_21 + 1 ;
}
static int F_15 ( T_1 * V_7 , void * V_1 , unsigned long V_34 ,
const T_2 * V_35 )
{
int V_21 , V_3 ;
int type ;
char V_19 ;
unsigned short V_5 ;
V_19 = 0 ;
V_5 = ( unsigned short ) ( V_34 & V_17 ) ;
type = V_35 -> type ;
V_21 = 0 ;
if ( V_34 & V_44 ) {
const char * V_45 ;
V_45 = F_16 ( type ) ;
V_21 += strlen ( V_45 ) ;
if ( ! V_7 ( V_1 , V_45 , V_21 ) || ! V_7 ( V_1 , L_8 , 1 ) )
return - 1 ;
V_21 ++ ;
}
if ( V_34 & V_46 )
type = - 1 ;
else if ( V_34 & V_47 )
type = 1 ;
else {
if ( ( type > 0 ) && ( type < 31 ) )
type = V_48 [ type ] ;
else
type = - 1 ;
if ( ( type == - 1 ) && ! ( V_34 & V_49 ) )
type = 1 ;
}
if ( type == - 1 ) {
V_3 = F_11 ( V_34 , V_7 , V_1 , V_35 ) ;
if ( V_3 < 0 )
return - 1 ;
V_21 += V_3 ;
return V_21 ;
}
if ( V_34 & V_50 ) {
if ( ! type )
type = 1 ;
else
type |= V_29 ;
}
V_3 = F_7 ( V_35 -> V_40 , V_35 -> V_41 , type , V_5 , & V_19 , V_7 , NULL ) ;
if ( V_3 < 0 )
return - 1 ;
V_21 += V_3 ;
if ( V_19 )
V_21 += 2 ;
if ( ! V_1 )
return V_21 ;
if ( V_19 && ! V_7 ( V_1 , L_9 , 1 ) )
return - 1 ;
if ( F_7 ( V_35 -> V_40 , V_35 -> V_41 , type , V_5 , NULL , V_7 , V_1 ) < 0 )
return - 1 ;
if ( V_19 && ! V_7 ( V_1 , L_9 , 1 ) )
return - 1 ;
return V_21 ;
}
static int F_17 ( T_1 * V_7 , void * V_1 , int V_51 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_51 ; V_20 ++ )
if ( ! V_7 ( V_1 , L_10 , 1 ) )
return 0 ;
return 1 ;
}
static int F_18 ( T_1 * V_7 , void * V_1 , const T_4 * V_52 ,
int V_51 , unsigned long V_5 )
{
int V_20 , V_53 = - 1 , V_22 , V_54 ;
int V_55 , V_56 ;
T_5 * V_57 ;
const T_2 * V_58 ;
const T_6 * V_59 ;
char V_60 [ 80 ] ;
const char * V_61 ;
int V_21 , V_3 ;
char * V_62 , * V_63 , * V_64 ;
int V_65 , V_66 , V_67 ;
if ( V_51 < 0 )
V_51 = 0 ;
V_21 = V_51 ;
if ( ! F_17 ( V_7 , V_1 , V_51 ) )
return - 1 ;
switch ( V_5 & V_68 ) {
case V_69 :
V_62 = L_11 ;
V_65 = 1 ;
V_63 = L_12 ;
V_66 = 3 ;
break;
case V_70 :
V_62 = L_13 ;
V_65 = 1 ;
V_63 = L_14 ;
V_66 = 1 ;
V_51 = 0 ;
break;
case V_71 :
V_62 = L_15 ;
V_65 = 2 ;
V_63 = L_12 ;
V_66 = 3 ;
V_51 = 0 ;
break;
case V_72 :
V_62 = L_16 ;
V_65 = 2 ;
V_63 = L_12 ;
V_66 = 3 ;
V_51 = 0 ;
break;
default:
return - 1 ;
}
if ( V_5 & V_73 ) {
V_64 = L_17 ;
V_67 = 3 ;
} else {
V_64 = L_18 ;
V_67 = 1 ;
}
V_55 = V_5 & V_74 ;
V_54 = F_19 ( V_52 ) ;
for ( V_20 = 0 ; V_20 < V_54 ; V_20 ++ ) {
if ( V_5 & V_75 )
V_59 = F_20 ( V_52 , V_54 - V_20 - 1 ) ;
else
V_59 = F_20 ( V_52 , V_20 ) ;
if ( V_53 != - 1 ) {
if ( V_53 == F_21 ( V_59 ) ) {
if ( ! V_7 ( V_1 , V_63 , V_66 ) )
return - 1 ;
V_21 += V_66 ;
} else {
if ( ! V_7 ( V_1 , V_62 , V_65 ) )
return - 1 ;
V_21 += V_65 ;
if ( ! F_17 ( V_7 , V_1 , V_51 ) )
return - 1 ;
V_21 += V_51 ;
}
}
V_53 = F_21 ( V_59 ) ;
V_57 = F_22 ( V_59 ) ;
V_58 = F_23 ( V_59 ) ;
V_56 = F_24 ( V_57 ) ;
if ( V_55 != V_76 ) {
int V_77 , V_78 ;
if ( ( V_55 == V_79 ) || ( V_56 == V_80 ) ) {
F_25 ( V_60 , sizeof V_60 , V_57 , 1 ) ;
V_78 = 0 ;
V_61 = V_60 ;
} else {
if ( V_55 == V_81 ) {
V_78 = V_82 ;
V_61 = F_26 ( V_56 ) ;
} else if ( V_55 == V_83 ) {
V_78 = V_84 ;
V_61 = F_27 ( V_56 ) ;
} else {
V_78 = 0 ;
V_61 = L_19 ;
}
}
V_77 = strlen ( V_61 ) ;
if ( ! V_7 ( V_1 , V_61 , V_77 ) )
return - 1 ;
if ( ( V_77 < V_78 ) && ( V_5 & V_85 ) ) {
if ( ! F_17 ( V_7 , V_1 , V_78 - V_77 ) )
return - 1 ;
V_21 += V_78 - V_77 ;
}
if ( ! V_7 ( V_1 , V_64 , V_67 ) )
return - 1 ;
V_21 += V_77 + V_67 ;
}
if ( ( V_56 == V_80 ) && ( V_5 & V_86 ) )
V_22 = V_46 ;
else
V_22 = 0 ;
V_3 = F_15 ( V_7 , V_1 , V_5 | V_22 , V_58 ) ;
if ( V_3 < 0 )
return - 1 ;
V_21 += V_3 ;
}
return V_21 ;
}
int F_28 ( T_7 * V_87 , const T_4 * V_88 , int V_51 ,
unsigned long V_5 )
{
if ( V_5 == V_89 )
return F_29 ( V_87 , V_88 , V_51 ) ;
return F_18 ( F_1 , V_87 , V_88 , V_51 , V_5 ) ;
}
int F_30 ( T_8 * V_90 , const T_4 * V_88 , int V_51 ,
unsigned long V_5 )
{
if ( V_5 == V_89 ) {
T_7 * V_91 ;
int V_92 ;
V_91 = F_31 ( V_90 , V_93 ) ;
if ( ! V_91 )
return - 1 ;
V_92 = F_29 ( V_91 , V_88 , V_51 ) ;
F_32 ( V_91 ) ;
return V_92 ;
}
return F_18 ( F_3 , V_90 , V_88 , V_51 , V_5 ) ;
}
int F_33 ( T_7 * V_87 , const T_2 * V_35 , unsigned long V_5 )
{
return F_15 ( F_1 , V_87 , V_5 , V_35 ) ;
}
int F_34 ( T_8 * V_90 , const T_2 * V_35 , unsigned long V_5 )
{
return F_15 ( F_3 , V_90 , V_5 , V_35 ) ;
}
int F_35 ( unsigned char * * V_87 , const T_2 * V_94 )
{
T_2 V_95 , * V_35 = & V_95 ;
int V_96 , type , V_92 ;
if ( ! V_94 )
return - 1 ;
type = V_94 -> type ;
if ( ( type < 0 ) || ( type > 30 ) )
return - 1 ;
V_96 = V_48 [ type ] ;
if ( V_96 == - 1 )
return - 1 ;
V_96 |= V_97 ;
V_95 . V_40 = NULL ;
V_95 . V_41 = 0 ;
V_95 . V_5 = 0 ;
V_92 =
F_36 ( & V_35 , V_94 -> V_40 , V_94 -> V_41 , V_96 ,
V_98 ) ;
if ( V_92 < 0 )
return V_92 ;
* V_87 = V_95 . V_40 ;
return V_95 . V_41 ;
}
int F_37 ( const T_2 * V_99 )
{
int V_100 = V_99 -> V_41 ;
const unsigned char * V_101 = V_99 -> V_40 ;
int type = V_99 -> type ;
int V_20 ;
char V_102 = - 1 ;
unsigned short V_103 = 0 , V_104 ;
if ( type > 0 && type < 31 )
V_102 = V_48 [ type ] ;
if ( V_102 == - 1 || V_100 == 0 )
return 0 ;
if ( V_102 == 0 )
V_102 = 1 ;
for ( V_20 = 0 ; V_20 < V_100 ; V_20 += V_102 ) {
V_104 = V_103 ;
if ( V_102 == 4 ) {
if ( * V_101 ++ != 0 || * V_101 ++ != 0 || * V_101 ++ != 0 )
return 0 ;
} else if ( V_102 == 2 ) {
if ( * V_101 ++ != 0 )
return 0 ;
}
if ( * V_101 > 0x7f )
return 0 ;
V_103 = V_12 [ * V_101 ++ ] ;
if ( ! ( V_103 & ( V_105 | V_106 ) ) ) {
if ( V_20 == 0 || V_20 == V_100 - 1 )
return 0 ;
if ( ! ( V_103 & ( V_107 | V_108 ) ) )
return 0 ;
if ( V_104 & ( V_107 | V_108 )
&& ( ( V_104 & V_107 )
|| ( V_103 & V_107 ) ) )
return 0 ;
}
}
return 1 ;
}
