int T_1 F_1 ( unsigned long V_1 ,
const char * V_2 , int V_3 , void * V_4 )
{
const void * V_5 , * V_6 ;
unsigned long V_7 , V_8 ;
T_2 V_9 ;
if ( V_3 != 1 || strcmp ( V_2 , L_1 ) != 0 )
return 0 ;
V_5 = F_2 ( V_1 , L_2 , & V_7 ) ;
V_6 = F_2 ( V_1 , L_3 , & V_8 ) ;
if ( ! V_5 || ! V_6 )
return 1 ;
V_10 . V_11 = F_3 ( V_5 , V_7 / 4 ) ;
V_10 . V_12 = F_3 ( V_6 , V_8 / 4 ) ;
F_4 ( L_4 ,
V_10 . V_11 , V_5 , V_7 ) ;
F_4 ( L_5 ,
V_10 . V_12 , V_6 , V_8 ) ;
V_13 |= V_14 ;
if ( F_5 ( V_1 , L_6 ) ) {
V_13 |= V_15 ;
F_6 ( L_7 ) ;
} else {
F_6 ( L_8 ) ;
}
V_9 = 0x7000 ;
F_7 ( V_16 ,
F_8 ( V_17 [ 0 ] ) ,
V_9 ) ;
V_9 += 128 ;
F_7 ( V_18 ,
0 , V_9 ) ;
V_9 += 128 ;
F_7 ( V_19 , 0 , V_9 ) ;
return 1 ;
}
int F_9 ( T_3 V_20 , char * V_21 , int V_22 )
{
T_4 V_23 , V_24 ;
T_2 V_25 ;
if ( ! V_10 . V_12 )
return - V_26 ;
F_10 ( & V_25 ) ;
if ( ( V_25 & V_27 ) == 0 )
return 0 ;
V_23 = V_22 ;
V_24 = F_11 ( V_20 , & V_23 , V_21 ) ;
if ( V_24 == V_28 )
return V_23 ;
return 0 ;
}
int F_12 ( T_3 V_20 , const char * V_4 , int V_29 )
{
int V_30 = 0 ;
T_4 V_23 , V_24 ;
unsigned long V_31 ;
T_2 V_25 ;
if ( ! V_10 . V_12 )
return - V_26 ;
F_13 ( & V_32 , V_31 ) ;
if ( F_14 ( V_15 ) ) {
V_24 = F_15 ( V_20 , & V_23 ) ;
if ( V_24 || V_23 < V_29 ) {
F_16 ( & V_32 , V_31 ) ;
if ( V_24 )
return V_29 ;
F_10 ( & V_25 ) ;
return - V_33 ;
}
}
V_24 = V_34 ;
while( V_29 > 0 && ( V_24 == V_34 ||
V_24 == V_35 || V_24 == V_28 ) ) {
V_23 = V_29 ;
V_24 = F_17 ( V_20 , & V_23 , V_4 ) ;
if ( V_24 == V_28 ) {
V_29 -= V_23 ;
V_4 += V_23 ;
V_30 += V_23 ;
}
do
F_10 ( & V_25 ) ;
while( V_24 == V_28 && ( V_25 & V_36 ) );
}
F_16 ( & V_32 , V_31 ) ;
return V_30 ;
}
int F_18 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = F_19 () -> V_41 ;
struct V_39 V_25 ;
const char * V_42 , * V_43 , * V_44 ;
static const char * V_45 [] = {
L_9 ,
L_10 ,
L_11 ,
L_12 ,
L_13 ,
} ;
static const char * V_46 [] = {
L_9 ,
L_14 ,
L_15 ,
} ;
static const char * V_47 [] = {
L_9 ,
L_14 ,
L_15 ,
} ;
static const char * V_48 [] = {
L_9 ,
L_14 ,
L_15 ,
} ;
V_25 = * V_40 ;
V_40 -> V_49 = 0 ;
if ( V_25 . V_50 != V_51 ) {
F_20 ( L_16 ,
V_25 . V_50 ) ;
return 0 ;
}
switch( V_25 . V_52 ) {
case V_53 :
V_42 = V_54 ;
V_43 = L_17 ;
break;
case V_55 :
V_42 = V_56 ;
V_43 = L_18 ;
break;
case V_57 :
V_42 = V_58 ;
V_43 = L_19 ;
break;
case V_59 :
default:
V_42 = V_58 ;
V_43 = L_20 ;
break;
}
F_6 ( L_21 , V_42 , V_43 ,
V_25 . V_60 == V_61 ?
L_22 : L_23 ) ;
F_6 ( L_24 , V_42 ,
V_25 . V_62 == V_63 ? L_25 : L_26 ) ;
switch( V_25 . V_64 ) {
case V_65 :
V_44 = V_25 . V_66 . V_67 . V_68 <
F_21 ( V_45 ) ?
V_45 [ V_25 . V_66 . V_67 . V_68 ]
: L_26 ;
F_6 ( L_27 , V_42 , V_44 ) ;
if ( V_25 . V_66 . V_67 . V_69 )
F_6 ( L_28 ,
V_42 , V_25 . V_66 . V_67 . V_70 ) ;
if ( V_25 . V_66 . V_67 . V_71 )
F_6 ( L_29 ,
V_42 , V_25 . V_66 . V_67 . V_72 ) ;
break;
case V_73 :
V_44 = V_25 . V_66 . V_74 . V_75 <
F_21 ( V_46 ) ?
V_46 [ V_25 . V_66 . V_74 . V_75 ]
: L_26 ;
F_6 ( L_30 , V_42 , V_44 ) ;
if ( V_25 . V_66 . V_74 . V_69 )
F_6 ( L_28 ,
V_42 , V_25 . V_66 . V_74 . V_70 ) ;
break;
case V_76 :
V_44 = V_25 . V_66 . V_77 . V_78 <
F_21 ( V_47 ) ?
V_47 [ V_25 . V_66 . V_77 . V_78 ]
: L_26 ;
F_6 ( L_31 , V_42 , V_44 ) ;
if ( V_25 . V_66 . V_77 . V_69 )
F_6 ( L_28 ,
V_42 , V_25 . V_66 . V_77 . V_70 ) ;
break;
case V_79 :
V_44 = V_25 . V_66 . V_80 . V_81 <
F_21 ( V_48 ) ?
V_48 [ V_25 . V_66 . V_80 . V_81 ]
: L_26 ;
F_6 ( L_32 , V_42 , V_44 ) ;
if ( V_25 . V_66 . V_80 . V_69 )
F_6 ( L_28 ,
V_42 , V_25 . V_66 . V_80 . V_70 ) ;
break;
default:
case V_82 :
F_6 ( L_33 , V_42 ) ;
break;
}
return V_25 . V_52 == V_59 ? 0 : 1 ;
}
static T_5 F_22 ( int V_83 , void * V_4 )
{
T_6 V_84 ;
F_23 ( F_24 ( V_83 ) , & V_84 ) ;
return V_85 ;
}
static int T_1 F_25 ( void )
{
struct V_86 * V_87 , * V_88 ;
const T_7 * V_89 ;
int V_24 , V_90 , V_91 ;
V_92 = F_26 ( L_34 ) ;
if ( ! V_92 ) {
F_27 ( L_35 ) ;
return - V_26 ;
}
if ( F_14 ( V_15 ) )
V_88 = F_26 ( L_36 ) ;
else
V_88 = F_28 ( V_92 ) ;
F_29 (consoles, np) {
if ( strcmp ( V_87 -> V_93 , L_37 ) )
continue;
F_30 ( V_87 , NULL , NULL ) ;
}
F_31 ( V_88 ) ;
V_89 = F_32 ( V_92 , L_38 , & V_91 ) ;
F_4 ( L_39 ,
V_89 ? ( V_91 / 4 ) : 0 ) ;
for ( V_90 = 0 ; V_89 && V_90 < ( V_91 / 4 ) ; V_90 ++ , V_89 ++ ) {
unsigned int V_94 = F_33 ( V_89 ) ;
unsigned int V_83 = F_34 ( NULL , V_94 ) ;
if ( V_83 == V_95 ) {
F_35 ( L_40 , V_94 ) ;
continue;
}
V_24 = F_36 ( V_83 , F_22 , 0 , L_41 , NULL ) ;
if ( V_24 )
F_35 ( L_42
L_43 , V_24 , V_83 , V_94 ) ;
}
return 0 ;
}
