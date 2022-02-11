int T_1 F_1 ( unsigned long V_1 ,
const char * V_2 , int V_3 , void * V_4 )
{
const void * V_5 , * V_6 ;
unsigned long V_7 , V_8 ;
if ( V_3 != 1 || strcmp ( V_2 , L_1 ) != 0 )
return 0 ;
V_5 = F_2 ( V_1 , L_2 , & V_7 ) ;
V_6 = F_2 ( V_1 , L_3 , & V_8 ) ;
if ( ! V_5 || ! V_6 )
return 1 ;
V_9 . V_10 = F_3 ( V_5 , V_7 / 4 ) ;
V_9 . V_11 = F_3 ( V_6 , V_8 / 4 ) ;
F_4 ( L_4 ,
V_9 . V_10 , V_5 , V_7 ) ;
F_4 ( L_5 ,
V_9 . V_11 , V_6 , V_8 ) ;
V_12 |= V_13 ;
if ( F_5 ( V_1 , L_6 ) ) {
V_12 |= V_14 ;
V_12 |= V_15 ;
F_6 ( L_7 ) ;
} else if ( F_5 ( V_1 , L_8 ) ) {
V_12 |= V_14 ;
F_6 ( L_9 ) ;
} else {
F_6 ( L_10 ) ;
}
return 1 ;
}
static int T_1 F_7 ( void )
{
#ifdef F_8
T_2 V_16 ;
if ( ! ( V_12 & V_13 ) )
return - V_17 ;
V_16 = 0x7000 ;
F_9 ( V_18 ,
F_10 ( V_19 [ 0 ] ) ,
V_16 ) ;
V_16 += 128 ;
F_9 ( V_20 ,
0 , V_16 ) ;
V_16 += 128 ;
F_9 ( V_21 , 0 , V_16 ) ;
#endif
return 0 ;
}
int F_11 ( struct V_22 * V_23 )
{
if ( ! V_23 ) {
F_12 ( L_11 ,
V_24 , V_23 ) ;
return - V_25 ;
}
F_13 ( & V_26 , V_23 ) ;
return 0 ;
}
static void F_14 ( T_3 V_27 )
{
unsigned long V_28 ;
T_3 V_29 ;
if ( F_15 ( & V_30 ) )
return;
F_16 ( & V_31 , V_28 ) ;
V_29 = V_32 ^ V_27 ;
V_32 = V_27 ;
F_17 ( & V_31 , V_28 ) ;
F_18 ( & V_26 ,
V_27 , ( void * ) V_29 ) ;
}
void F_19 ( T_3 V_33 ,
T_3 V_34 )
{
unsigned long V_28 ;
F_16 ( & V_31 , V_28 ) ;
V_32 &= ~ V_33 ;
V_32 |= V_34 ;
F_17 ( & V_31 , V_28 ) ;
}
void F_20 ( void )
{
T_4 V_35 ;
T_3 V_36 = 0 ;
F_21 ( & V_30 , 0 ) ;
V_35 = F_22 ( & V_36 ) ;
if ( V_35 == V_37 && V_36 )
F_14 ( V_36 ) ;
}
void F_23 ( void )
{
F_21 ( & V_30 , 1 ) ;
}
int F_24 ( T_5 V_38 , char * V_39 , int V_40 )
{
T_6 V_35 ;
T_7 V_36 , V_41 ;
if ( ! V_9 . V_11 )
return - V_17 ;
F_22 ( & V_36 ) ;
if ( ( F_25 ( V_36 ) & V_42 ) == 0 )
return 0 ;
V_41 = F_26 ( V_40 ) ;
V_35 = F_27 ( V_38 , & V_41 , V_39 ) ;
if ( V_35 == V_37 )
return F_25 ( V_41 ) ;
return 0 ;
}
int F_28 ( T_5 V_38 , const char * V_4 , int V_43 )
{
int V_44 = 0 ;
T_7 V_45 ;
T_6 V_41 , V_35 ;
unsigned long V_28 ;
T_7 V_36 ;
if ( ! V_9 . V_11 )
return - V_17 ;
F_16 ( & V_46 , V_28 ) ;
if ( F_29 ( V_14 ) ) {
V_35 = F_30 ( V_38 , & V_45 ) ;
V_41 = F_25 ( V_45 ) ;
if ( V_35 || V_41 < V_43 ) {
F_17 ( & V_46 , V_28 ) ;
if ( V_35 )
return V_43 ;
F_22 ( NULL ) ;
return - V_47 ;
}
}
V_35 = V_48 ;
while( V_43 > 0 && ( V_35 == V_48 ||
V_35 == V_49 || V_35 == V_37 ) ) {
V_45 = F_26 ( V_43 ) ;
V_35 = F_31 ( V_38 , & V_45 , V_4 ) ;
V_41 = F_25 ( V_45 ) ;
if ( V_35 != V_37 && V_35 != V_48 &&
V_35 != V_49 ) {
V_44 = V_43 ;
break;
}
if ( V_35 == V_37 ) {
V_43 -= V_41 ;
V_4 += V_41 ;
V_44 += V_41 ;
}
do
F_22 ( & V_36 ) ;
while( V_35 == V_37 &&
( F_25 ( V_36 ) & V_50 ) );
}
F_17 ( & V_46 , V_28 ) ;
return V_44 ;
}
int F_32 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_33 () -> V_55 ;
struct V_53 V_36 ;
const char * V_56 , * V_57 , * V_58 ;
static const char * V_59 [] = {
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16 ,
} ;
static const char * V_60 [] = {
L_12 ,
L_17 ,
L_18 ,
} ;
static const char * V_61 [] = {
L_12 ,
L_17 ,
L_18 ,
} ;
static const char * V_62 [] = {
L_12 ,
L_17 ,
L_18 ,
} ;
V_36 = * V_54 ;
V_54 -> V_63 = 0 ;
if ( V_36 . V_64 != V_65 ) {
F_34 ( L_19 ,
V_36 . V_64 ) ;
return 0 ;
}
switch( V_36 . V_66 ) {
case V_67 :
V_56 = V_68 ;
V_57 = L_20 ;
break;
case V_69 :
V_56 = V_70 ;
V_57 = L_21 ;
break;
case V_71 :
V_56 = V_72 ;
V_57 = L_22 ;
break;
case V_73 :
default:
V_56 = V_72 ;
V_57 = L_23 ;
break;
}
F_6 ( L_24 , V_56 , V_57 ,
V_36 . V_74 == V_75 ?
L_25 : L_26 ) ;
F_6 ( L_27 , V_56 ,
V_36 . V_76 == V_77 ? L_28 : L_29 ) ;
switch( V_36 . V_78 ) {
case V_79 :
V_58 = V_36 . V_80 . V_81 . V_82 <
F_35 ( V_59 ) ?
V_59 [ V_36 . V_80 . V_81 . V_82 ]
: L_29 ;
F_6 ( L_30 , V_56 , V_58 ) ;
if ( V_36 . V_80 . V_81 . V_83 )
F_6 ( L_31 ,
V_56 , V_36 . V_80 . V_81 . V_84 ) ;
if ( V_36 . V_80 . V_81 . V_85 )
F_6 ( L_32 ,
V_56 , V_36 . V_80 . V_81 . V_86 ) ;
break;
case V_87 :
V_58 = V_36 . V_80 . V_88 . V_89 <
F_35 ( V_60 ) ?
V_60 [ V_36 . V_80 . V_88 . V_89 ]
: L_29 ;
F_6 ( L_33 , V_56 , V_58 ) ;
if ( V_36 . V_80 . V_88 . V_83 )
F_6 ( L_31 ,
V_56 , V_36 . V_80 . V_88 . V_84 ) ;
break;
case V_90 :
V_58 = V_36 . V_80 . V_91 . V_92 <
F_35 ( V_61 ) ?
V_61 [ V_36 . V_80 . V_91 . V_92 ]
: L_29 ;
F_6 ( L_34 , V_56 , V_58 ) ;
if ( V_36 . V_80 . V_91 . V_83 )
F_6 ( L_31 ,
V_56 , V_36 . V_80 . V_91 . V_84 ) ;
break;
case V_93 :
V_58 = V_36 . V_80 . V_94 . V_95 <
F_35 ( V_62 ) ?
V_62 [ V_36 . V_80 . V_94 . V_95 ]
: L_29 ;
F_6 ( L_35 , V_56 , V_58 ) ;
if ( V_36 . V_80 . V_94 . V_83 )
F_6 ( L_31 ,
V_56 , V_36 . V_80 . V_94 . V_84 ) ;
break;
default:
case V_96 :
F_6 ( L_36 , V_56 ) ;
break;
}
return V_36 . V_66 == V_73 ? 0 : 1 ;
}
static T_8 F_36 ( int V_97 , void * V_4 )
{
T_7 V_27 ;
F_37 ( F_38 ( V_97 ) , & V_27 ) ;
F_14 ( V_27 ) ;
return V_98 ;
}
static int F_39 ( void )
{
V_99 = F_40 ( L_37 , V_100 ) ;
if ( ! V_99 ) {
F_41 ( L_38 ) ;
return - V_101 ;
}
return 0 ;
}
static int T_1 F_42 ( void )
{
struct V_102 * V_103 , * V_104 ;
const T_9 * V_105 ;
int V_35 , V_106 , V_107 ;
V_108 = F_43 ( L_39 ) ;
if ( ! V_108 ) {
F_41 ( L_40 ) ;
return - V_17 ;
}
if ( F_29 ( V_14 ) )
V_104 = F_43 ( L_41 ) ;
else
V_104 = F_44 ( V_108 ) ;
if ( V_104 ) {
F_45 (consoles, np) {
if ( strcmp ( V_103 -> V_109 , L_42 ) )
continue;
F_46 ( V_103 , NULL , NULL ) ;
}
F_47 ( V_104 ) ;
}
V_105 = F_48 ( V_108 , L_43 , & V_107 ) ;
F_4 ( L_44 ,
V_105 ? ( V_107 / 4 ) : 0 ) ;
V_110 = V_107 / 4 ;
V_111 = F_49 ( V_110 * sizeof( unsigned int ) , V_112 ) ;
for ( V_106 = 0 ; V_105 && V_106 < ( V_107 / 4 ) ; V_106 ++ , V_105 ++ ) {
unsigned int V_113 = F_50 ( V_105 ) ;
unsigned int V_97 = F_51 ( NULL , V_113 ) ;
if ( V_97 == V_114 ) {
F_12 ( L_45 , V_113 ) ;
continue;
}
V_35 = F_52 ( V_97 , F_36 , 0 , L_37 , NULL ) ;
if ( V_35 )
F_12 ( L_46
L_47 , V_35 , V_97 , V_113 ) ;
V_111 [ V_106 ] = V_97 ;
}
V_35 = F_39 () ;
if ( V_35 == 0 ) {
F_53 () ;
}
return 0 ;
}
void F_54 ( void )
{
unsigned int V_106 ;
for ( V_106 = 0 ; V_106 < V_110 ; V_106 ++ ) {
if ( V_111 [ V_106 ] )
F_55 ( V_111 [ V_106 ] , NULL ) ;
V_111 [ V_106 ] = 0 ;
}
}
