T_1 F_1 ( const T_2 * V_1 )
{
return V_1 -> V_2 . V_3 ;
}
int F_2 ( T_2 * V_4 )
{
return V_4 -> V_2 . V_5 ;
}
int F_3 ( T_2 * V_4 )
{
return ! ( V_4 -> V_2 . V_5 ) && ( V_4 -> V_2 . V_3 == V_6 ) ;
}
int F_4 ( T_2 * V_4 )
{
return ( V_4 -> V_2 . V_3 == V_7 )
&& ( V_4 -> V_2 . V_8 == V_9 ) ;
}
void F_5 ( T_2 * V_4 )
{
V_4 -> V_2 . V_8 = V_9 ;
V_4 -> V_2 . V_3 = V_7 ;
V_4 -> V_2 . V_5 = 1 ;
V_4 -> V_2 . V_10 = 0 ;
}
void F_6 ( T_2 * V_4 )
{
V_4 -> V_2 . V_8 = V_11 ;
V_4 -> V_2 . V_5 = 1 ;
}
void F_7 ( T_2 * V_4 )
{
V_4 -> V_2 . V_8 = V_12 ;
}
int F_8 ( const T_2 * V_4 )
{
if ( V_4 -> V_2 . V_8 == V_12 )
return 1 ;
return 0 ;
}
void F_9 ( T_2 * V_4 , int V_13 )
{
V_4 -> V_2 . V_5 = V_13 ;
}
int F_10 ( T_2 * V_4 )
{
return V_4 -> V_2 . V_14 ;
}
void F_11 ( T_2 * V_4 , int V_15 )
{
if ( V_15 )
V_4 -> V_2 . V_14 ++ ;
else
V_4 -> V_2 . V_14 -- ;
}
void F_12 ( T_2 * V_4 )
{
V_4 -> V_2 . V_8 = V_9 ;
V_4 -> V_2 . V_5 = 1 ;
V_4 -> V_2 . V_3 = V_16 ;
}
int F_13 ( T_2 * V_4 )
{
return F_14 ( V_4 , 0 ) ;
}
int F_15 ( T_2 * V_4 )
{
return F_14 ( V_4 , 1 ) ;
}
static T_3 F_16 ( T_2 * V_4 )
{
if ( V_4 -> V_17 != NULL )
return V_4 -> V_17 ;
else if ( V_4 -> V_18 -> V_17 != NULL )
return V_4 -> V_18 -> V_17 ;
return NULL ;
}
static int F_14 ( T_2 * V_4 , int V_19 )
{
T_4 * V_20 = NULL ;
unsigned long Time = ( unsigned long ) time ( NULL ) ;
void (* F_17) ( const T_2 * V_1 , int type , int V_21 ) = NULL ;
T_5 * V_22 = & V_4 -> V_2 ;
int V_23 = - 1 ;
int V_24 ;
if ( V_22 -> V_8 == V_12 ) {
return - 1 ;
}
F_18 ( & Time , sizeof( Time ) , 0 ) ;
F_19 () ;
F_20 () ;
F_17 = F_16 ( V_4 ) ;
V_22 -> V_14 ++ ;
if ( ! F_2 ( V_4 ) || F_4 ( V_4 ) ) {
if ( ! F_21 ( V_4 ) )
return - 1 ;
}
#ifndef F_22
if ( F_23 ( V_4 ) ) {
F_24 ( F_25 ( V_4 ) , V_25 ,
V_22 -> V_14 , NULL ) ;
}
#endif
#ifndef F_26
if ( V_4 -> V_26 ) {
if ( F_23 ( V_4 ) )
F_27 ( V_4 ) ;
V_4 -> V_26 = 0 ;
V_4 -> V_27 ++ ;
}
#endif
if ( V_22 -> V_8 == V_11 ) {
V_4 -> V_28 = 1 ;
if ( ! V_19 )
V_4 -> V_18 -> V_29 . V_30 ++ ;
}
if ( V_22 -> V_8 == V_9 || V_22 -> V_8 == V_11 ) {
if ( V_22 -> V_8 == V_9 ) {
V_22 -> V_3 = V_7 ;
}
V_4 -> V_19 = V_19 ;
if ( F_17 != NULL )
F_17 ( V_4 , V_31 , 1 ) ;
if ( F_23 ( V_4 ) ) {
if ( ( V_4 -> V_32 & 0xff00 ) != ( V_33 & 0xff00 ) &&
( V_19 || ( V_4 -> V_32 & 0xff00 ) != ( V_34 & 0xff00 ) ) ) {
F_28 ( V_35 , V_36 ) ;
goto V_37;
}
} else {
if ( ( V_4 -> V_32 >> 8 ) != V_38 ) {
F_28 ( V_35 , V_36 ) ;
goto V_37;
}
}
if ( ! F_29 ( V_4 , V_39 , 0 , V_4 -> V_32 , NULL ) ) {
F_28 ( V_35 , V_40 ) ;
goto V_37;
}
if ( V_4 -> V_41 == NULL ) {
if ( ( V_20 = F_30 () ) == NULL ) {
goto V_37;
}
if ( ! F_31 ( V_20 , V_42 ) ) {
goto V_37;
}
V_4 -> V_41 = V_20 ;
V_20 = NULL ;
}
if ( ! F_32 ( V_4 ) ) {
goto V_37;
}
V_4 -> V_43 = 0 ;
V_4 -> V_44 -> V_45 = 0 ;
#ifndef F_22
if ( ! F_23 ( V_4 ) || ! F_33 ( F_25 ( V_4 ) ) )
#endif
if ( ! F_34 ( V_4 ) ) {
goto V_37;
}
if ( ! V_19 || V_22 -> V_8 != V_11 ) {
if ( ! F_35 ( V_4 ) ) {
F_7 ( V_4 ) ;
goto V_37;
}
}
if ( V_19 ) {
if ( V_22 -> V_8 != V_11 ) {
V_4 -> V_18 -> V_29 . V_46 ++ ;
} else if ( ! V_4 -> V_44 -> V_47 &&
! ( V_4 -> V_48 &
V_49 ) ) {
F_28 ( V_35 ,
V_50 ) ;
F_36 ( V_4 , V_51 , V_52 ) ;
F_7 ( V_4 ) ;
goto V_37;
} else {
V_4 -> V_18 -> V_29 . V_53 ++ ;
}
} else {
V_4 -> V_18 -> V_29 . V_54 ++ ;
memset ( V_4 -> V_44 -> V_55 , 0 , sizeof( V_4 -> V_44 -> V_55 ) ) ;
V_4 -> V_56 = 0 ;
V_4 -> V_44 -> V_57 . V_58 = 0 ;
if ( F_23 ( V_4 ) ) {
V_22 -> V_59 = 1 ;
}
}
V_22 -> V_8 = V_60 ;
F_37 ( V_4 ) ;
V_22 -> V_61 = 1 ;
}
while ( V_22 -> V_8 != V_62 ) {
if ( V_22 -> V_8 == V_63 ) {
V_24 = F_38 ( V_4 ) ;
if ( V_24 == V_64 ) {
V_22 -> V_8 = V_60 ;
F_37 ( V_4 ) ;
} else {
goto V_37;
}
} else if ( V_22 -> V_8 == V_60 ) {
V_24 = F_39 ( V_4 ) ;
if ( V_24 == V_64 ) {
V_22 -> V_8 = V_63 ;
F_40 ( V_4 ) ;
} else if ( V_24 == V_65 ) {
V_22 -> V_8 = V_62 ;
} else {
goto V_37;
}
} else {
F_7 ( V_4 ) ;
goto V_37;
}
}
V_22 -> V_8 = V_9 ;
V_23 = 1 ;
V_37:
V_22 -> V_14 -- ;
#ifndef F_22
if ( F_23 ( V_4 ) ) {
F_24 ( F_25 ( V_4 ) , V_25 ,
V_22 -> V_14 , NULL ) ;
}
#endif
F_41 ( V_20 ) ;
if ( F_17 != NULL ) {
if ( V_19 )
F_17 ( V_4 , V_66 , V_23 ) ;
else
F_17 ( V_4 , V_67 , V_23 ) ;
}
return V_23 ;
}
static void F_40 ( T_2 * V_4 )
{
T_5 * V_22 = & V_4 -> V_2 ;
V_22 -> V_68 = V_69 ;
}
static T_6 F_38 ( T_2 * V_4 )
{
T_5 * V_22 = & V_4 -> V_2 ;
int V_23 , V_70 ;
unsigned long V_71 = 0 ;
int (* F_42) ( T_2 * V_4 , int V_70 );
T_7 V_72 ;
T_8 (* F_43) ( T_2 * V_4 , T_7 * V_72 );
T_9 (* F_44) ( T_2 * V_4 , T_9 V_73 );
unsigned long ( * V_74 ) ( T_2 * V_4 ) ;
void (* F_17) ( const T_2 * V_1 , int type , int V_21 ) = NULL ;
F_17 = F_16 ( V_4 ) ;
if ( V_4 -> V_19 ) {
F_42 = V_75 ;
F_43 = V_76 ;
V_74 = V_77 ;
F_44 = V_78 ;
} else {
F_42 = V_79 ;
F_43 = V_80 ;
V_74 = V_81 ;
F_44 = V_82 ;
}
if ( V_22 -> V_61 ) {
V_4 -> V_83 = 1 ;
V_22 -> V_61 = 0 ;
}
while ( 1 ) {
switch ( V_22 -> V_68 ) {
case V_69 :
if ( F_23 ( V_4 ) ) {
V_23 = F_45 ( V_4 , & V_70 , & V_71 ) ;
} else {
V_23 = F_46 ( V_4 , & V_70 ) ;
}
if ( V_23 == 0 ) {
return V_84 ;
}
if ( F_17 != NULL ) {
if ( V_4 -> V_19 )
F_17 ( V_4 , V_85 , 1 ) ;
else
F_17 ( V_4 , V_86 , 1 ) ;
}
if ( ! F_42 ( V_4 , V_70 ) ) {
F_7 ( V_4 ) ;
return V_84 ;
}
if ( V_4 -> V_44 -> V_57 . V_87 > V_74 ( V_4 ) ) {
F_36 ( V_4 , V_51 , V_88 ) ;
F_28 ( V_89 , V_90 ) ;
return V_84 ;
}
V_22 -> V_68 = V_91 ;
case V_91 :
if ( ! F_23 ( V_4 ) ) {
V_23 = F_47 ( V_4 , & V_71 ) ;
if ( V_23 == 0 ) {
return V_84 ;
}
}
V_4 -> V_83 = 0 ;
if ( ! F_48 ( & V_72 , V_4 -> V_92 , V_71 ) ) {
F_36 ( V_4 , V_51 , V_93 ) ;
F_28 ( V_89 , V_36 ) ;
return V_84 ;
}
V_23 = F_43 ( V_4 , & V_72 ) ;
V_4 -> V_43 = 0 ;
if ( V_23 == V_94 ) {
return V_84 ;
}
if ( V_23 == V_95 ) {
if ( F_23 ( V_4 ) ) {
F_27 ( V_4 ) ;
}
return V_64 ;
}
if ( V_23 == V_96 ) {
V_22 -> V_68 = V_97 ;
V_22 -> V_98 = V_99 ;
} else {
V_22 -> V_68 = V_69 ;
}
break;
case V_97 :
V_22 -> V_98 = F_44 ( V_4 , V_22 -> V_98 ) ;
switch ( V_22 -> V_98 ) {
default:
return V_84 ;
case V_100 :
V_22 -> V_68 = V_69 ;
break;
case V_101 :
if ( F_23 ( V_4 ) ) {
F_27 ( V_4 ) ;
}
return V_64 ;
}
break;
default:
F_36 ( V_4 , V_51 , V_93 ) ;
F_28 ( V_89 , V_36 ) ;
F_7 ( V_4 ) ;
return V_84 ;
}
}
}
static int F_49 ( T_2 * V_4 )
{
T_5 * V_22 = & V_4 -> V_2 ;
if ( V_22 -> V_3 == V_102
|| V_22 -> V_3 == V_103 ) {
if ( F_23 ( V_4 ) )
return F_50 ( V_4 , V_104 ) ;
else
return F_51 ( V_4 , V_104 ) ;
} else {
return F_52 ( V_4 ) ;
}
}
static void F_37 ( T_2 * V_4 )
{
T_5 * V_22 = & V_4 -> V_2 ;
V_22 -> V_105 = V_106 ;
}
static T_6 F_39 ( T_2 * V_4 )
{
T_5 * V_22 = & V_4 -> V_2 ;
int V_23 ;
T_10 (* F_42) ( T_2 * V_4 );
T_9 (* F_53) ( T_2 * V_4 , T_9 V_73 );
T_9 (* F_54) ( T_2 * V_4 , T_9 V_73 );
int (* F_55) ( T_2 * V_4 );
void (* F_17) ( const T_2 * V_1 , int type , int V_21 ) = NULL ;
F_17 = F_16 ( V_4 ) ;
if ( V_4 -> V_19 ) {
F_42 = V_107 ;
F_53 = V_108 ;
F_54 = V_109 ;
F_55 = V_110 ;
} else {
F_42 = V_111 ;
F_53 = V_112 ;
F_54 = V_113 ;
F_55 = V_114 ;
}
while ( 1 ) {
switch ( V_22 -> V_105 ) {
case V_106 :
if ( F_17 != NULL ) {
if ( V_4 -> V_19 )
F_17 ( V_4 , V_85 , 1 ) ;
else
F_17 ( V_4 , V_86 , 1 ) ;
}
switch ( F_42 ( V_4 ) ) {
case V_115 :
V_22 -> V_105 = V_116 ;
V_22 -> V_117 = V_99 ;
break;
case V_118 :
return V_64 ;
break;
default:
return V_84 ;
}
break;
case V_116 :
switch ( V_22 -> V_117 = F_53 ( V_4 , V_22 -> V_117 ) ) {
default:
return V_84 ;
case V_100 :
V_22 -> V_105 = V_119 ;
break;
case V_101 :
return V_65 ;
}
if ( F_55 ( V_4 ) == 0 )
return V_84 ;
case V_119 :
if ( F_23 ( V_4 ) && V_22 -> V_59 ) {
F_56 ( V_4 ) ;
}
V_23 = F_49 ( V_4 ) ;
if ( V_23 <= 0 ) {
return V_84 ;
}
V_22 -> V_105 = V_120 ;
V_22 -> V_117 = V_99 ;
case V_120 :
switch ( V_22 -> V_117 = F_54 ( V_4 , V_22 -> V_117 ) ) {
default:
return V_84 ;
case V_100 :
V_22 -> V_105 = V_106 ;
break;
case V_101 :
return V_65 ;
}
break;
default:
return V_84 ;
}
}
}
int F_57 ( T_2 * V_4 )
{
V_4 -> V_121 = V_122 ;
if ( F_58 ( V_4 -> V_123 ) <= 0 ) {
return 0 ;
}
V_4 -> V_121 = V_124 ;
return 1 ;
}
int F_59 ( T_2 * V_4 )
{
T_5 * V_22 = & V_4 -> V_2 ;
if ( V_22 -> V_8 == V_9 || V_22 -> V_8 == V_11 )
return 0 ;
if ( ! V_4 -> V_44 -> V_125 || ( V_4 -> V_44 -> V_126 == 0 ) )
return 0 ;
if ( V_4 -> V_19 ) {
if ( V_22 -> V_3 == V_7
|| V_22 -> V_3 == V_16 )
return 1 ;
} else {
if ( V_22 -> V_3 == V_127 )
return 1 ;
}
return 0 ;
}
void F_60 ( T_2 * V_4 , int V_128 )
{
V_4 -> V_2 . V_129 = V_128 ;
}
int F_61 ( T_2 * V_4 )
{
return V_4 -> V_2 . V_129 ;
}
