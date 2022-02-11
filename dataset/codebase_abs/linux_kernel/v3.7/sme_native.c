int
F_1 ( T_1 * V_1 )
{
F_2 () ;
F_3 ( & V_1 -> V_2 , 1 ) ;
#ifdef F_4
{
int V_3 = F_5 ( V_1 ) ;
if ( V_3 != 0 ) {
F_6 () ;
return V_3 ;
}
}
#endif
F_6 () ;
return 0 ;
}
void
F_7 ( T_1 * V_1 )
{
F_2 () ;
F_8 ( V_1 -> V_4 ) ;
#ifdef F_4
F_9 ( V_1 ) ;
#endif
F_6 () ;
}
int F_10 ( T_1 * V_1 )
{
int V_3 , V_5 ;
T_2 V_6 ;
if ( V_1 == NULL ) {
return - V_7 ;
}
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ ) {
V_1 -> V_9 [ V_5 ] -> V_10 = 0 ;
}
V_1 -> V_9 [ 0 ] -> V_10 = V_11 ;
V_3 = F_11 ( V_1 , V_12 ) ;
if ( V_3 ) {
F_12 ( V_1 , L_1 ) ;
return V_3 ;
}
V_1 -> V_13 . V_14 = 1 ;
F_13 ( V_1 -> V_15 ) ;
V_6 = F_14 ( V_1 -> V_15 ) ;
F_15 ( V_1 -> V_15 ) ;
if( V_6 != V_16 && V_6 != V_17 ) {
return - V_18 ;
}
if ( V_6 == V_16 ) {
V_3 = F_16 ( V_1 ) ;
if ( V_3 ) {
return V_3 ;
}
}
V_1 -> V_13 . V_14 = 0 ;
V_6 = F_17 ( V_1 -> V_19 ,
V_20 ,
V_21 ) ;
if ( V_6 != V_16 ) {
F_18 ( V_1 ,
L_2 ) ;
}
F_13 ( V_1 -> V_15 ) ;
V_3 = F_19 ( V_1 ) ;
if ( V_3 ) {
F_20 ( V_1 -> V_15 ) ;
F_15 ( V_1 -> V_15 ) ;
return V_3 ;
}
F_15 ( V_1 -> V_15 ) ;
V_1 -> V_22 = V_23 ;
return 0 ;
}
int
F_21 ( T_1 * V_1 )
{
const int V_24 = 0 ;
T_3 V_6 ;
F_22 ( V_1 ) ;
V_1 -> V_25 = 0 ;
F_23 ( V_1 , V_1 -> V_26 [ V_24 ] -> V_27 , 0 ) ;
F_24 ( V_1 -> V_26 [ V_24 ] ) ;
F_13 ( V_1 -> V_15 ) ;
V_6 = F_25 ( V_1 -> V_19 ) ;
F_15 ( V_1 -> V_15 ) ;
return 0 ;
}
int
F_26 ( T_1 * V_1 )
{
#ifdef F_4
memset ( V_1 -> V_28 . V_29 , 0 , V_30 ) ;
memset ( ( void * ) V_1 -> V_28 . V_31 , 0 , V_32 ) ;
V_1 -> V_28 . V_33 = 0 ;
F_27 ( V_1 ) ;
#endif
return 0 ;
}
void
F_28 ( T_4 * V_34 ,
const T_5 * V_35 , int V_36 ,
const T_6 * V_37 ,
int V_38 )
{
T_1 * V_1 ;
T_7 * V_39 ;
T_5 * V_40 ;
int V_5 , V_3 ;
int V_41 ;
int V_42 ;
T_8 * V_43 ;
T_9 signal ;
T_4 * V_44 = V_34 ;
F_2 () ;
if ( V_44 == NULL ) {
F_12 ( NULL , L_3 ) ;
return;
}
V_1 = F_29 ( V_44 -> V_45 ) ;
if ( ! V_1 ) {
F_12 ( V_1 , L_4 ) ;
return;
}
if ( ( V_35 == NULL ) || ( V_36 <= 0 ) ) {
return;
}
V_3 = F_30 ( V_35 , & signal ) ;
if ( V_3 == 0 ) {
V_41 = F_31 ( & signal ) ;
} else {
T_10 V_46 = F_32 ( ( V_35 ) + sizeof( T_10 ) ) & 0xFF00 ;
if ( V_36 == 1 ) {
F_33 ( V_1 , V_47 ,
L_5 ,
* V_35 ) ;
* ( T_5 * ) & signal = * V_35 ;
V_41 = V_36 ;
} else if ( V_46 == 0 ) {
F_33 ( V_1 , V_47 ,
L_6 ,
F_32 ( V_35 ) ) ;
* ( T_5 * ) & signal = * V_35 ;
V_41 = V_36 ;
} else {
F_12 ( V_1 ,
L_7 ,
F_32 ( V_35 ) ) ;
return;
}
}
F_33 ( V_1 , V_48 , L_8 ,
signal . V_49 . V_50 ,
V_44 -> V_51 ) ;
V_42 = V_41 ;
for ( V_5 = 0 ; V_5 < V_52 ; V_5 ++ ) {
V_42 += V_37 -> V_53 [ V_5 ] . V_54 ;
}
V_39 = ( T_7 * ) F_34 ( sizeof( T_7 ) + V_42 , V_55 ) ;
if ( V_39 == NULL ) {
F_12 ( V_1 ,
L_9 ,
sizeof( T_7 ) + V_42 ) ;
return;
}
F_35 ( & V_39 -> V_56 ) ;
V_43 = & V_39 -> V_57 ;
V_43 -> V_58 = sizeof( T_8 ) + V_42 ;
V_43 -> V_59 = F_36 ( V_60 ) ;
V_43 -> V_61 = V_38 ;
V_43 -> V_62 = V_41 ;
V_40 = ( T_5 * ) ( V_43 + 1 ) ;
memcpy ( V_40 , & signal , V_41 ) ;
V_40 += V_41 ;
for ( V_5 = 0 ; V_5 < V_52 ; V_5 ++ ) {
int V_63 = V_37 -> V_53 [ V_5 ] . V_54 ;
if ( V_63 > 0 ) {
if ( V_37 -> V_53 [ V_5 ] . V_64 ) {
memcpy ( V_40 , V_37 -> V_53 [ V_5 ] . V_64 , V_63 ) ;
} else {
memset ( V_40 , 0 , V_63 ) ;
}
V_40 += V_63 ;
}
}
F_37 ( & V_44 -> V_65 ) ;
F_38 ( & V_39 -> V_56 , & V_44 -> V_66 ) ;
F_39 ( & V_44 -> V_65 ) ;
F_40 ( & V_44 -> V_67 ) ;
F_6 () ;
}
void
F_41 ( void * V_68 ,
T_11 V_69 ,
T_12 V_61 ,
const T_13 * V_70 )
{
}
void
F_42 ( void * V_68 , T_14 * V_71 )
{
}
void
F_43 ( void * V_68 ,
T_15 V_72 ,
T_15 V_73 ,
T_15 V_74 ,
T_15 V_75 )
{
}
void
F_44 ( T_4 * V_34 ,
const T_5 * V_76 , int V_77 ,
const T_6 * V_37 , int V_38 )
{
}
void
F_45 ( T_4 * V_34 ,
const T_5 * V_35 , int V_36 ,
const T_6 * V_37 ,
int V_38 )
{
T_9 signal ;
int V_41 ;
T_1 * V_1 = F_29 ( V_34 -> V_45 ) ;
int V_78 , V_3 ;
F_2 () ;
if ( ( V_35 == NULL ) || ( V_36 <= 0 ) ) {
return;
}
V_3 = F_30 ( V_35 , & signal ) ;
if ( V_3 == 0 ) {
V_41 = F_31 ( & signal ) ;
} else {
F_12 ( V_1 ,
L_10 ,
F_32 ( V_35 ) ) ;
return;
}
V_78 = signal . V_49 . V_50 ;
F_33 ( V_1 , V_79 , L_11 , V_78 ) ;
switch ( V_78 ) {
case V_80 :
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
F_46 ( V_34 , & signal , V_41 , V_37 ) ;
break;
case V_120 :
F_47 ( V_1 , L_12 ) ;
break;
default:
break;
}
F_6 () ;
}
int
F_23 ( T_1 * V_1 , unsigned char * V_121 ,
unsigned char V_122 )
{
int V_3 = 0 ;
F_2 () ;
#ifdef F_4
V_1 -> V_28 . V_123 = 0 ;
#endif
F_6 () ;
return V_3 ;
}
