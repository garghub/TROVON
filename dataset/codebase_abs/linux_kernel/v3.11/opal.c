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
T_2 V_16 ;
if ( ! ( V_12 & V_13 ) )
return - V_17 ;
V_16 = 0x7000 ;
F_8 ( V_18 ,
F_9 ( V_19 [ 0 ] ) ,
V_16 ) ;
V_16 += 128 ;
F_8 ( V_20 ,
0 , V_16 ) ;
V_16 += 128 ;
F_8 ( V_21 , 0 , V_16 ) ;
return 0 ;
}
int F_10 ( struct V_22 * V_23 )
{
if ( ! V_23 ) {
F_11 ( L_11 ,
V_24 , V_23 ) ;
return - V_25 ;
}
F_12 ( & V_26 , V_23 ) ;
return 0 ;
}
static void F_13 ( T_3 V_27 )
{
unsigned long V_28 ;
T_3 V_29 ;
if ( F_14 ( & V_30 ) )
return;
F_15 ( & V_31 , V_28 ) ;
V_29 = V_32 ^ V_27 ;
V_32 = V_27 ;
F_16 ( & V_31 , V_28 ) ;
F_17 ( & V_26 ,
V_27 , ( void * ) V_29 ) ;
}
void F_18 ( T_3 V_33 ,
T_3 V_34 )
{
unsigned long V_28 ;
F_15 ( & V_31 , V_28 ) ;
V_32 &= ~ V_33 ;
V_32 |= V_34 ;
F_16 ( & V_31 , V_28 ) ;
}
void F_19 ( void )
{
T_4 V_35 ;
T_3 V_36 = 0 ;
F_20 ( & V_30 , 0 ) ;
V_35 = F_21 ( & V_36 ) ;
if ( V_35 == V_37 && V_36 )
F_13 ( V_36 ) ;
}
void F_22 ( void )
{
F_20 ( & V_30 , 1 ) ;
}
int F_23 ( T_5 V_38 , char * V_39 , int V_40 )
{
T_6 V_41 , V_35 ;
T_2 V_36 ;
if ( ! V_9 . V_11 )
return - V_17 ;
F_21 ( & V_36 ) ;
if ( ( V_36 & V_42 ) == 0 )
return 0 ;
V_41 = V_40 ;
V_35 = F_24 ( V_38 , & V_41 , V_39 ) ;
if ( V_35 == V_37 )
return V_41 ;
return 0 ;
}
int F_25 ( T_5 V_38 , const char * V_4 , int V_43 )
{
int V_44 = 0 ;
T_6 V_41 , V_35 ;
unsigned long V_28 ;
T_2 V_36 ;
if ( ! V_9 . V_11 )
return - V_17 ;
F_15 ( & V_45 , V_28 ) ;
if ( F_26 ( V_14 ) ) {
V_35 = F_27 ( V_38 , & V_41 ) ;
if ( V_35 || V_41 < V_43 ) {
F_16 ( & V_45 , V_28 ) ;
if ( V_35 )
return V_43 ;
F_21 ( & V_36 ) ;
return - V_46 ;
}
}
V_35 = V_47 ;
while( V_43 > 0 && ( V_35 == V_47 ||
V_35 == V_48 || V_35 == V_37 ) ) {
V_41 = V_43 ;
V_35 = F_28 ( V_38 , & V_41 , V_4 ) ;
if ( V_35 != V_37 && V_35 != V_47 &&
V_35 != V_48 ) {
V_44 = V_43 ;
break;
}
if ( V_35 == V_37 ) {
V_43 -= V_41 ;
V_4 += V_41 ;
V_44 += V_41 ;
}
do
F_21 ( & V_36 ) ;
while( V_35 == V_37 && ( V_36 & V_49 ) );
}
F_16 ( & V_45 , V_28 ) ;
return V_44 ;
}
int F_29 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_30 () -> V_54 ;
struct V_52 V_36 ;
const char * V_55 , * V_56 , * V_57 ;
static const char * V_58 [] = {
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16 ,
} ;
static const char * V_59 [] = {
L_12 ,
L_17 ,
L_18 ,
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
V_36 = * V_53 ;
V_53 -> V_62 = 0 ;
if ( V_36 . V_63 != V_64 ) {
F_31 ( L_19 ,
V_36 . V_63 ) ;
return 0 ;
}
switch( V_36 . V_65 ) {
case V_66 :
V_55 = V_67 ;
V_56 = L_20 ;
break;
case V_68 :
V_55 = V_69 ;
V_56 = L_21 ;
break;
case V_70 :
V_55 = V_71 ;
V_56 = L_22 ;
break;
case V_72 :
default:
V_55 = V_71 ;
V_56 = L_23 ;
break;
}
F_6 ( L_24 , V_55 , V_56 ,
V_36 . V_73 == V_74 ?
L_25 : L_26 ) ;
F_6 ( L_27 , V_55 ,
V_36 . V_75 == V_76 ? L_28 : L_29 ) ;
switch( V_36 . V_77 ) {
case V_78 :
V_57 = V_36 . V_79 . V_80 . V_81 <
F_32 ( V_58 ) ?
V_58 [ V_36 . V_79 . V_80 . V_81 ]
: L_29 ;
F_6 ( L_30 , V_55 , V_57 ) ;
if ( V_36 . V_79 . V_80 . V_82 )
F_6 ( L_31 ,
V_55 , V_36 . V_79 . V_80 . V_83 ) ;
if ( V_36 . V_79 . V_80 . V_84 )
F_6 ( L_32 ,
V_55 , V_36 . V_79 . V_80 . V_85 ) ;
break;
case V_86 :
V_57 = V_36 . V_79 . V_87 . V_88 <
F_32 ( V_59 ) ?
V_59 [ V_36 . V_79 . V_87 . V_88 ]
: L_29 ;
F_6 ( L_33 , V_55 , V_57 ) ;
if ( V_36 . V_79 . V_87 . V_82 )
F_6 ( L_31 ,
V_55 , V_36 . V_79 . V_87 . V_83 ) ;
break;
case V_89 :
V_57 = V_36 . V_79 . V_90 . V_91 <
F_32 ( V_60 ) ?
V_60 [ V_36 . V_79 . V_90 . V_91 ]
: L_29 ;
F_6 ( L_34 , V_55 , V_57 ) ;
if ( V_36 . V_79 . V_90 . V_82 )
F_6 ( L_31 ,
V_55 , V_36 . V_79 . V_90 . V_83 ) ;
break;
case V_92 :
V_57 = V_36 . V_79 . V_93 . V_94 <
F_32 ( V_61 ) ?
V_61 [ V_36 . V_79 . V_93 . V_94 ]
: L_29 ;
F_6 ( L_35 , V_55 , V_57 ) ;
if ( V_36 . V_79 . V_93 . V_82 )
F_6 ( L_31 ,
V_55 , V_36 . V_79 . V_93 . V_83 ) ;
break;
default:
case V_95 :
F_6 ( L_36 , V_55 ) ;
break;
}
return V_36 . V_65 == V_72 ? 0 : 1 ;
}
static T_7 F_33 ( int V_96 , void * V_4 )
{
T_3 V_27 ;
F_34 ( F_35 ( V_96 ) , & V_27 ) ;
F_13 ( V_27 ) ;
return V_97 ;
}
static int T_1 F_36 ( void )
{
struct V_98 * V_99 , * V_100 ;
const T_8 * V_101 ;
int V_35 , V_102 , V_103 ;
V_104 = F_37 ( L_37 ) ;
if ( ! V_104 ) {
F_38 ( L_38 ) ;
return - V_17 ;
}
if ( F_26 ( V_14 ) )
V_100 = F_37 ( L_39 ) ;
else
V_100 = F_39 ( V_104 ) ;
F_40 (consoles, np) {
if ( strcmp ( V_99 -> V_105 , L_40 ) )
continue;
F_41 ( V_99 , NULL , NULL ) ;
}
F_42 ( V_100 ) ;
V_101 = F_43 ( V_104 , L_41 , & V_103 ) ;
F_4 ( L_42 ,
V_101 ? ( V_103 / 4 ) : 0 ) ;
V_106 = V_103 / 4 ;
V_107 = F_44 ( V_106 * sizeof( unsigned int ) , V_108 ) ;
for ( V_102 = 0 ; V_101 && V_102 < ( V_103 / 4 ) ; V_102 ++ , V_101 ++ ) {
unsigned int V_109 = F_45 ( V_101 ) ;
unsigned int V_96 = F_46 ( NULL , V_109 ) ;
if ( V_96 == V_110 ) {
F_11 ( L_43 , V_109 ) ;
continue;
}
V_35 = F_47 ( V_96 , F_33 , 0 , L_44 , NULL ) ;
if ( V_35 )
F_11 ( L_45
L_46 , V_35 , V_96 , V_109 ) ;
V_107 [ V_102 ] = V_96 ;
}
return 0 ;
}
void F_48 ( void )
{
unsigned int V_102 ;
for ( V_102 = 0 ; V_102 < V_106 ; V_102 ++ ) {
if ( V_107 [ V_102 ] )
F_49 ( V_107 [ V_102 ] , 0 ) ;
V_107 [ V_102 ] = 0 ;
}
}
