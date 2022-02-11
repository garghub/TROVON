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
int F_10 ( T_3 V_22 , char * V_23 , int V_24 )
{
T_4 V_25 , V_26 ;
T_2 V_27 ;
if ( ! V_9 . V_11 )
return - V_17 ;
F_11 ( & V_27 ) ;
if ( ( V_27 & V_28 ) == 0 )
return 0 ;
V_25 = V_24 ;
V_26 = F_12 ( V_22 , & V_25 , V_23 ) ;
if ( V_26 == V_29 )
return V_25 ;
return 0 ;
}
int F_13 ( T_3 V_22 , const char * V_4 , int V_30 )
{
int V_31 = 0 ;
T_4 V_25 , V_26 ;
unsigned long V_32 ;
T_2 V_27 ;
if ( ! V_9 . V_11 )
return - V_17 ;
F_14 ( & V_33 , V_32 ) ;
if ( F_15 ( V_14 ) ) {
V_26 = F_16 ( V_22 , & V_25 ) ;
if ( V_26 || V_25 < V_30 ) {
F_17 ( & V_33 , V_32 ) ;
if ( V_26 )
return V_30 ;
F_11 ( & V_27 ) ;
return - V_34 ;
}
}
V_26 = V_35 ;
while( V_30 > 0 && ( V_26 == V_35 ||
V_26 == V_36 || V_26 == V_29 ) ) {
V_25 = V_30 ;
V_26 = F_18 ( V_22 , & V_25 , V_4 ) ;
if ( V_26 != V_29 && V_26 != V_35 &&
V_26 != V_36 ) {
V_31 = V_30 ;
break;
}
if ( V_26 == V_29 ) {
V_30 -= V_25 ;
V_4 += V_25 ;
V_31 += V_25 ;
}
do
F_11 ( & V_27 ) ;
while( V_26 == V_29 && ( V_27 & V_37 ) );
}
F_17 ( & V_33 , V_32 ) ;
return V_31 ;
}
int F_19 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_20 () -> V_42 ;
struct V_40 V_27 ;
const char * V_43 , * V_44 , * V_45 ;
static const char * V_46 [] = {
L_11 ,
L_12 ,
L_13 ,
L_14 ,
L_15 ,
} ;
static const char * V_47 [] = {
L_11 ,
L_16 ,
L_17 ,
} ;
static const char * V_48 [] = {
L_11 ,
L_16 ,
L_17 ,
} ;
static const char * V_49 [] = {
L_11 ,
L_16 ,
L_17 ,
} ;
V_27 = * V_41 ;
V_41 -> V_50 = 0 ;
if ( V_27 . V_51 != V_52 ) {
F_21 ( L_18 ,
V_27 . V_51 ) ;
return 0 ;
}
switch( V_27 . V_53 ) {
case V_54 :
V_43 = V_55 ;
V_44 = L_19 ;
break;
case V_56 :
V_43 = V_57 ;
V_44 = L_20 ;
break;
case V_58 :
V_43 = V_59 ;
V_44 = L_21 ;
break;
case V_60 :
default:
V_43 = V_59 ;
V_44 = L_22 ;
break;
}
F_6 ( L_23 , V_43 , V_44 ,
V_27 . V_61 == V_62 ?
L_24 : L_25 ) ;
F_6 ( L_26 , V_43 ,
V_27 . V_63 == V_64 ? L_27 : L_28 ) ;
switch( V_27 . V_65 ) {
case V_66 :
V_45 = V_27 . V_67 . V_68 . V_69 <
F_22 ( V_46 ) ?
V_46 [ V_27 . V_67 . V_68 . V_69 ]
: L_28 ;
F_6 ( L_29 , V_43 , V_45 ) ;
if ( V_27 . V_67 . V_68 . V_70 )
F_6 ( L_30 ,
V_43 , V_27 . V_67 . V_68 . V_71 ) ;
if ( V_27 . V_67 . V_68 . V_72 )
F_6 ( L_31 ,
V_43 , V_27 . V_67 . V_68 . V_73 ) ;
break;
case V_74 :
V_45 = V_27 . V_67 . V_75 . V_76 <
F_22 ( V_47 ) ?
V_47 [ V_27 . V_67 . V_75 . V_76 ]
: L_28 ;
F_6 ( L_32 , V_43 , V_45 ) ;
if ( V_27 . V_67 . V_75 . V_70 )
F_6 ( L_30 ,
V_43 , V_27 . V_67 . V_75 . V_71 ) ;
break;
case V_77 :
V_45 = V_27 . V_67 . V_78 . V_79 <
F_22 ( V_48 ) ?
V_48 [ V_27 . V_67 . V_78 . V_79 ]
: L_28 ;
F_6 ( L_33 , V_43 , V_45 ) ;
if ( V_27 . V_67 . V_78 . V_70 )
F_6 ( L_30 ,
V_43 , V_27 . V_67 . V_78 . V_71 ) ;
break;
case V_80 :
V_45 = V_27 . V_67 . V_81 . V_82 <
F_22 ( V_49 ) ?
V_49 [ V_27 . V_67 . V_81 . V_82 ]
: L_28 ;
F_6 ( L_34 , V_43 , V_45 ) ;
if ( V_27 . V_67 . V_81 . V_70 )
F_6 ( L_30 ,
V_43 , V_27 . V_67 . V_81 . V_71 ) ;
break;
default:
case V_83 :
F_6 ( L_35 , V_43 ) ;
break;
}
return V_27 . V_53 == V_60 ? 0 : 1 ;
}
static T_5 F_23 ( int V_84 , void * V_4 )
{
T_6 V_85 ;
F_24 ( F_25 ( V_84 ) , & V_85 ) ;
return V_86 ;
}
static int T_1 F_26 ( void )
{
struct V_87 * V_88 , * V_89 ;
const T_7 * V_90 ;
int V_26 , V_91 , V_92 ;
V_93 = F_27 ( L_36 ) ;
if ( ! V_93 ) {
F_28 ( L_37 ) ;
return - V_17 ;
}
if ( F_15 ( V_14 ) )
V_89 = F_27 ( L_38 ) ;
else
V_89 = F_29 ( V_93 ) ;
F_30 (consoles, np) {
if ( strcmp ( V_88 -> V_94 , L_39 ) )
continue;
F_31 ( V_88 , NULL , NULL ) ;
}
F_32 ( V_89 ) ;
V_90 = F_33 ( V_93 , L_40 , & V_92 ) ;
F_4 ( L_41 ,
V_90 ? ( V_92 / 4 ) : 0 ) ;
V_95 = V_92 / 4 ;
V_96 = F_34 ( V_95 * sizeof( unsigned int ) , V_97 ) ;
for ( V_91 = 0 ; V_90 && V_91 < ( V_92 / 4 ) ; V_91 ++ , V_90 ++ ) {
unsigned int V_98 = F_35 ( V_90 ) ;
unsigned int V_84 = F_36 ( NULL , V_98 ) ;
if ( V_84 == V_99 ) {
F_37 ( L_42 , V_98 ) ;
continue;
}
V_26 = F_38 ( V_84 , F_23 , 0 , L_43 , NULL ) ;
if ( V_26 )
F_37 ( L_44
L_45 , V_26 , V_84 , V_98 ) ;
V_96 [ V_91 ] = V_84 ;
}
return 0 ;
}
void F_39 ( void )
{
unsigned int V_91 ;
for ( V_91 = 0 ; V_91 < V_95 ; V_91 ++ ) {
if ( V_96 [ V_91 ] )
F_40 ( V_96 [ V_91 ] , 0 ) ;
V_96 [ V_91 ] = 0 ;
}
}
