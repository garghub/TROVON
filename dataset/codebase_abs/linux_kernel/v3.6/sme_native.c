int
F_1 ( T_1 * V_1 )
{
F_2 () ;
#if V_2 >= F_3 ( 2 , 6 , 37 )
F_4 ( & V_1 -> V_3 , 1 ) ;
#else
F_5 ( & V_1 -> V_3 ) ;
#endif
#ifdef F_6
{
int V_4 = F_7 ( V_1 ) ;
if ( V_4 != 0 ) {
F_8 () ;
return V_4 ;
}
}
#endif
F_8 () ;
return 0 ;
}
void
F_9 ( T_1 * V_1 )
{
F_2 () ;
F_10 ( V_1 -> V_5 ) ;
#ifdef F_6
F_11 ( V_1 ) ;
#endif
F_8 () ;
}
int F_12 ( T_1 * V_1 )
{
int V_4 , V_6 ;
T_2 V_7 ;
if ( V_1 == NULL ) {
return - V_8 ;
}
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
V_1 -> V_10 [ V_6 ] -> V_11 = 0 ;
}
V_1 -> V_10 [ 0 ] -> V_11 = V_12 ;
V_4 = F_13 ( V_1 , V_13 ) ;
if ( V_4 ) {
F_14 ( V_1 , L_1 ) ;
return V_4 ;
}
V_1 -> V_14 . V_15 = 1 ;
F_15 ( V_1 -> V_16 ) ;
V_7 = F_16 ( V_1 -> V_16 ) ;
F_17 ( V_1 -> V_16 ) ;
if( V_7 != V_17 && V_7 != V_18 ) {
return - V_19 ;
}
if ( V_7 == V_17 ) {
V_4 = F_18 ( V_1 ) ;
if ( V_4 ) {
return V_4 ;
}
}
V_1 -> V_14 . V_15 = 0 ;
V_7 = F_19 ( V_1 -> V_20 ,
V_21 ,
V_22 ) ;
if ( V_7 != V_17 ) {
F_20 ( V_1 ,
L_2 ) ;
}
F_15 ( V_1 -> V_16 ) ;
V_4 = F_21 ( V_1 ) ;
if ( V_4 ) {
F_22 ( V_1 -> V_16 ) ;
F_17 ( V_1 -> V_16 ) ;
return V_4 ;
}
F_17 ( V_1 -> V_16 ) ;
V_1 -> V_23 = V_24 ;
return 0 ;
}
int
F_23 ( T_1 * V_1 )
{
const int V_25 = 0 ;
T_3 V_7 ;
F_24 ( V_1 ) ;
V_1 -> V_26 = 0 ;
F_25 ( V_1 , V_1 -> V_27 [ V_25 ] -> V_28 , 0 ) ;
F_26 ( V_1 -> V_27 [ V_25 ] ) ;
F_15 ( V_1 -> V_16 ) ;
V_7 = F_27 ( V_1 -> V_20 ) ;
F_17 ( V_1 -> V_16 ) ;
return 0 ;
}
int
F_28 ( T_1 * V_1 )
{
#ifdef F_6
memset ( V_1 -> V_29 . V_30 , 0 , V_31 ) ;
memset ( ( void * ) V_1 -> V_29 . V_32 , 0 , V_33 ) ;
V_1 -> V_29 . V_34 = 0 ;
F_29 ( V_1 ) ;
#endif
return 0 ;
}
void
F_30 ( T_4 * V_35 ,
const T_5 * V_36 , int V_37 ,
const T_6 * V_38 ,
int V_39 )
{
T_1 * V_1 ;
T_7 * V_40 ;
T_5 * V_41 ;
int V_6 , V_4 ;
int V_42 ;
int V_43 ;
T_8 * V_44 ;
T_9 signal ;
T_4 * V_45 = V_35 ;
F_2 () ;
if ( V_45 == NULL ) {
F_14 ( NULL , L_3 ) ;
return;
}
V_1 = F_31 ( V_45 -> V_46 ) ;
if ( ! V_1 ) {
F_14 ( V_1 , L_4 ) ;
return;
}
if ( ( V_36 == NULL ) || ( V_37 <= 0 ) ) {
return;
}
V_4 = F_32 ( V_36 , & signal ) ;
if ( V_4 == 0 ) {
V_42 = F_33 ( & signal ) ;
} else {
T_10 V_47 = F_34 ( ( V_36 ) + sizeof( T_10 ) ) & 0xFF00 ;
if ( V_37 == 1 ) {
F_35 ( V_1 , V_48 ,
L_5 ,
* V_36 ) ;
* ( T_5 * ) & signal = * V_36 ;
V_42 = V_37 ;
} else if ( V_47 == 0 ) {
F_35 ( V_1 , V_48 ,
L_6 ,
F_34 ( V_36 ) ) ;
* ( T_5 * ) & signal = * V_36 ;
V_42 = V_37 ;
} else {
F_14 ( V_1 ,
L_7 ,
F_34 ( V_36 ) ) ;
return;
}
}
F_35 ( V_1 , V_49 , L_8 ,
signal . V_50 . V_51 ,
V_45 -> V_52 ) ;
V_43 = V_42 ;
for ( V_6 = 0 ; V_6 < V_53 ; V_6 ++ ) {
V_43 += V_38 -> V_54 [ V_6 ] . V_55 ;
}
V_40 = ( T_7 * ) F_36 ( sizeof( T_7 ) + V_43 , V_56 ) ;
if ( V_40 == NULL ) {
F_14 ( V_1 ,
L_9 ,
sizeof( T_7 ) + V_43 ) ;
return;
}
F_37 ( & V_40 -> V_57 ) ;
V_44 = & V_40 -> V_58 ;
V_44 -> V_59 = sizeof( T_8 ) + V_43 ;
V_44 -> V_60 = F_38 ( V_61 ) ;
V_44 -> V_62 = V_39 ;
V_44 -> V_63 = V_42 ;
V_41 = ( T_5 * ) ( V_44 + 1 ) ;
memcpy ( V_41 , & signal , V_42 ) ;
V_41 += V_42 ;
for ( V_6 = 0 ; V_6 < V_53 ; V_6 ++ ) {
int V_64 = V_38 -> V_54 [ V_6 ] . V_55 ;
if ( V_64 > 0 ) {
if ( V_38 -> V_54 [ V_6 ] . V_65 ) {
memcpy ( V_41 , V_38 -> V_54 [ V_6 ] . V_65 , V_64 ) ;
} else {
memset ( V_41 , 0 , V_64 ) ;
}
V_41 += V_64 ;
}
}
F_39 ( & V_45 -> V_66 ) ;
F_40 ( & V_40 -> V_57 , & V_45 -> V_67 ) ;
F_41 ( & V_45 -> V_66 ) ;
F_42 ( & V_45 -> V_68 ) ;
F_8 () ;
}
void
F_43 ( void * V_69 ,
T_11 V_70 ,
T_12 V_62 ,
const T_13 * V_71 )
{
}
void
F_44 ( void * V_69 , T_14 * V_72 )
{
}
void
F_45 ( void * V_69 ,
T_15 V_73 ,
T_15 V_74 ,
T_15 V_75 ,
T_15 V_76 )
{
}
void
F_46 ( T_4 * V_35 ,
const T_5 * V_77 , int V_78 ,
const T_6 * V_38 , int V_39 )
{
}
void
F_47 ( T_4 * V_35 ,
const T_5 * V_36 , int V_37 ,
const T_6 * V_38 ,
int V_39 )
{
T_9 signal ;
int V_42 ;
T_1 * V_1 = F_31 ( V_35 -> V_46 ) ;
int V_79 , V_4 ;
F_2 () ;
if ( ( V_36 == NULL ) || ( V_37 <= 0 ) ) {
return;
}
V_4 = F_32 ( V_36 , & signal ) ;
if ( V_4 == 0 ) {
V_42 = F_33 ( & signal ) ;
} else {
F_14 ( V_1 ,
L_10 ,
F_34 ( V_36 ) ) ;
return;
}
V_79 = signal . V_50 . V_51 ;
F_35 ( V_1 , V_80 , L_11 , V_79 ) ;
switch ( V_79 ) {
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
F_48 ( V_35 , & signal , V_42 , V_38 ) ;
break;
case V_121 :
F_49 ( V_1 , L_12 ) ;
break;
default:
break;
}
F_8 () ;
}
int
F_25 ( T_1 * V_1 , unsigned char * V_122 ,
unsigned char V_123 )
{
int V_4 = 0 ;
F_2 () ;
#ifdef F_6
V_1 -> V_29 . V_124 = 0 ;
#endif
F_8 () ;
return V_4 ;
}
