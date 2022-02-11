int F_1 ( const char * V_1 ,
T_1 V_2 ,
const void * V_3 ,
const void * V_4 ,
struct V_5 * V_6 )
{
if ( V_3 == NULL && V_4 == NULL ) {
return F_2 ( V_1 , V_6 ) ;
} else if ( V_3 != NULL && V_4 != NULL ) {
switch ( V_2 ) {
case V_7 :
return F_3 ( V_1 , V_3 , V_4 ,
V_6 ) ;
default:
return - V_8 ;
}
} else
return - V_9 ;
}
int F_4 ( const char * V_1 ,
T_1 V_2 ,
const void * V_3 ,
const void * V_4 ,
struct V_5 * V_6 )
{
int V_10 = - V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_18 * V_19 = NULL ;
V_13 = F_5 ( sizeof( * V_13 ) , V_20 ) ;
if ( V_13 == NULL )
return - V_11 ;
if ( V_1 != NULL ) {
V_13 -> V_1 = F_6 ( V_1 , V_20 ) ;
if ( V_13 -> V_1 == NULL )
goto V_21;
}
if ( V_3 == NULL && V_4 == NULL )
V_13 -> V_22 . type = V_23 ;
else if ( V_3 != NULL && V_4 != NULL ) {
V_15 = F_5 ( sizeof( * V_15 ) , V_20 ) ;
if ( V_15 == NULL )
goto V_21;
F_7 ( & V_15 -> V_24 ) ;
F_7 ( & V_15 -> V_25 ) ;
switch ( V_2 ) {
case V_7 : {
const struct V_26 * V_27 = V_3 ;
const struct V_26 * V_28 = V_4 ;
V_17 = F_5 ( sizeof( * V_17 ) , V_20 ) ;
if ( V_17 == NULL )
goto V_21;
V_17 -> V_22 . type = V_23 ;
V_17 -> V_29 . V_3 = V_27 -> V_30 & V_28 -> V_30 ;
V_17 -> V_29 . V_4 = V_28 -> V_30 ;
V_17 -> V_29 . V_31 = 1 ;
V_10 = F_8 ( & V_17 -> V_29 ,
& V_15 -> V_24 ) ;
if ( V_10 != 0 )
goto V_21;
break;
}
#if F_9 ( V_32 )
case V_33 : {
const struct V_34 * V_35 = V_3 ;
const struct V_34 * V_36 = V_4 ;
V_19 = F_5 ( sizeof( * V_19 ) , V_20 ) ;
if ( V_19 == NULL )
goto V_21;
V_19 -> V_22 . type = V_23 ;
V_19 -> V_29 . V_3 = * V_35 ;
V_19 -> V_29 . V_3 . V_37 [ 0 ] &= V_36 -> V_37 [ 0 ] ;
V_19 -> V_29 . V_3 . V_37 [ 1 ] &= V_36 -> V_37 [ 1 ] ;
V_19 -> V_29 . V_3 . V_37 [ 2 ] &= V_36 -> V_37 [ 2 ] ;
V_19 -> V_29 . V_3 . V_37 [ 3 ] &= V_36 -> V_37 [ 3 ] ;
V_19 -> V_29 . V_4 = * V_36 ;
V_19 -> V_29 . V_31 = 1 ;
V_10 = F_10 ( & V_19 -> V_29 ,
& V_15 -> V_25 ) ;
if ( V_10 != 0 )
goto V_21;
break;
}
#endif
default:
goto V_21;
break;
}
V_13 -> V_22 . V_38 = V_15 ;
V_13 -> V_22 . type = V_39 ;
} else {
V_10 = - V_9 ;
goto V_21;
}
V_10 = F_11 ( V_13 , V_6 ) ;
if ( V_10 != 0 )
goto V_21;
return 0 ;
V_21:
F_12 ( V_13 -> V_1 ) ;
F_12 ( V_13 ) ;
F_12 ( V_15 ) ;
F_12 ( V_17 ) ;
F_12 ( V_19 ) ;
return V_10 ;
}
int F_13 ( struct V_40 * V_40 ,
const char * V_41 ,
const void * V_3 ,
const void * V_4 ,
T_1 V_2 ,
T_2 V_42 ,
struct V_5 * V_6 )
{
T_2 V_43 ;
switch ( V_2 ) {
case V_7 :
V_43 = sizeof( struct V_26 ) ;
break;
#if F_9 ( V_32 )
case V_33 :
V_43 = sizeof( struct V_34 ) ;
break;
#endif
default:
return - V_8 ;
}
return F_14 ( V_40 ,
V_41 , V_3 , V_4 , V_43 ,
V_42 , V_6 ) ;
}
int F_15 ( struct V_40 * V_40 ,
const char * V_41 ,
const void * V_3 ,
const void * V_4 ,
T_1 V_2 ,
struct V_5 * V_6 )
{
T_2 V_43 ;
switch ( V_2 ) {
case V_7 :
V_43 = sizeof( struct V_26 ) ;
break;
#if F_9 ( V_32 )
case V_33 :
V_43 = sizeof( struct V_34 ) ;
break;
#endif
default:
return - V_8 ;
}
return F_16 ( V_40 ,
V_41 , V_3 , V_4 , V_43 ,
V_6 ) ;
}
int F_17 ( struct V_44 * V_45 ,
struct V_5 * V_6 )
{
return F_18 ( V_45 , V_6 ) ;
}
void F_19 ( T_2 V_46 , struct V_5 * V_6 )
{
F_20 ( V_46 , V_6 ) ;
}
int F_21 ( T_2 V_46 ,
const char * V_1 ,
const struct V_26 * V_3 ,
const struct V_26 * V_4 ,
struct V_5 * V_6 )
{
int V_10 = - V_11 ;
struct V_44 * V_45 ;
struct V_12 * V_13 ;
struct V_14 * V_15 = NULL ;
struct V_16 * V_47 = NULL ;
V_45 = F_22 ( V_46 ) ;
if ( V_45 == NULL )
return - V_48 ;
V_13 = F_5 ( sizeof( * V_13 ) , V_20 ) ;
if ( V_13 == NULL )
goto V_49;
if ( V_1 != NULL ) {
V_13 -> V_1 = F_6 ( V_1 , V_20 ) ;
if ( V_13 -> V_1 == NULL )
goto V_50;
}
if ( V_3 == NULL && V_4 == NULL ) {
V_13 -> V_22 . V_51 = V_45 ;
V_13 -> V_22 . type = V_52 ;
} else if ( V_3 != NULL && V_4 != NULL ) {
V_15 = F_5 ( sizeof( * V_15 ) , V_20 ) ;
if ( V_15 == NULL )
goto V_53;
F_7 ( & V_15 -> V_24 ) ;
F_7 ( & V_15 -> V_25 ) ;
V_47 = F_5 ( sizeof( * V_47 ) , V_20 ) ;
if ( V_47 == NULL )
goto V_54;
V_47 -> V_22 . V_51 = V_45 ;
V_47 -> V_22 . type = V_52 ;
V_47 -> V_29 . V_3 = V_3 -> V_30 & V_4 -> V_30 ;
V_47 -> V_29 . V_4 = V_4 -> V_30 ;
V_47 -> V_29 . V_31 = 1 ;
V_10 = F_8 ( & V_47 -> V_29 , & V_15 -> V_24 ) ;
if ( V_10 != 0 )
goto V_55;
V_13 -> V_22 . V_38 = V_15 ;
V_13 -> V_22 . type = V_39 ;
} else {
V_10 = - V_9 ;
goto V_53;
}
V_10 = F_11 ( V_13 , V_6 ) ;
if ( V_10 != 0 )
goto V_55;
return 0 ;
V_55:
F_12 ( V_47 ) ;
V_54:
F_12 ( V_15 ) ;
V_53:
F_12 ( V_13 -> V_1 ) ;
V_50:
F_12 ( V_13 ) ;
V_49:
F_23 ( V_45 ) ;
return V_10 ;
}
int F_24 ( struct V_56 * V_57 ,
T_2 V_58 )
{
struct V_56 * V_59 = V_57 ;
T_2 V_60 ;
T_2 V_61 ;
T_3 V_62 ;
if ( V_58 > V_59 -> V_63 ) {
while ( V_58 >= ( V_59 -> V_63 + V_64 ) ) {
V_59 = V_59 -> V_65 ;
if ( V_59 == NULL )
return - V_48 ;
}
V_60 = ( V_58 - V_59 -> V_63 ) / V_66 ;
V_61 = V_58 - V_59 -> V_63 -
( V_66 * V_60 ) ;
} else {
V_60 = 0 ;
V_61 = 0 ;
}
V_62 = V_59 -> V_62 [ V_60 ] >> V_61 ;
for (; ; ) {
if ( V_62 != 0 ) {
while ( ( V_62 & V_67 ) == 0 ) {
V_62 >>= 1 ;
V_61 ++ ;
}
return V_59 -> V_63 +
( V_66 * V_60 ) + V_61 ;
}
if ( ++ V_60 >= V_68 ) {
if ( V_59 -> V_65 != NULL ) {
V_59 = V_59 -> V_65 ;
V_60 = 0 ;
} else
return - V_48 ;
}
V_62 = V_59 -> V_62 [ V_60 ] ;
V_61 = 0 ;
}
return - V_48 ;
}
int F_25 ( struct V_56 * V_57 ,
T_2 V_58 )
{
struct V_56 * V_59 = V_57 ;
T_2 V_60 ;
T_2 V_61 ;
T_3 V_69 ;
T_3 V_62 ;
if ( V_58 > V_59 -> V_63 ) {
while ( V_58 >= ( V_59 -> V_63 + V_64 ) ) {
V_59 = V_59 -> V_65 ;
if ( V_59 == NULL )
return - V_48 ;
}
V_60 = ( V_58 - V_59 -> V_63 ) / V_66 ;
V_61 = V_58 - V_59 -> V_63 -
( V_66 * V_60 ) ;
} else {
V_60 = 0 ;
V_61 = 0 ;
}
V_69 = V_67 << V_61 ;
for (; ; ) {
V_62 = V_59 -> V_62 [ V_60 ] ;
while ( V_69 != 0 && ( V_62 & V_69 ) != 0 ) {
V_69 <<= 1 ;
V_61 ++ ;
}
if ( V_69 != 0 )
return V_59 -> V_63 +
( V_66 * V_60 ) +
V_61 - 1 ;
else if ( ++ V_60 >= V_68 ) {
if ( V_59 -> V_65 == NULL )
return V_59 -> V_63 + V_64 - 1 ;
V_59 = V_59 -> V_65 ;
V_60 = 0 ;
}
V_69 = V_67 ;
V_61 = 0 ;
}
return - V_48 ;
}
int F_26 ( struct V_56 * V_57 ,
T_2 V_70 ,
T_4 V_71 )
{
struct V_56 * V_59 = V_57 ;
T_2 V_61 ;
T_2 V_60 ;
while ( V_59 -> V_65 != NULL &&
V_70 >= ( V_59 -> V_63 + V_64 ) )
V_59 = V_59 -> V_65 ;
if ( V_70 >= ( V_59 -> V_63 + V_64 ) ) {
V_59 -> V_65 = F_27 ( V_71 ) ;
if ( V_59 -> V_65 == NULL )
return - V_11 ;
V_59 = V_59 -> V_65 ;
V_59 -> V_63 = V_70 & ~ ( V_64 - 1 ) ;
}
V_60 = ( V_70 - V_59 -> V_63 ) / V_66 ;
V_61 = V_70 - V_59 -> V_63 - ( V_66 * V_60 ) ;
V_59 -> V_62 [ V_60 ] |= V_67 << V_61 ;
return 0 ;
}
int F_28 ( struct V_56 * V_57 ,
T_2 V_72 ,
T_2 V_73 ,
T_4 V_71 )
{
int V_10 = 0 ;
struct V_56 * V_59 = V_57 ;
T_2 V_74 ;
T_2 V_75 ;
while ( V_59 -> V_65 != NULL &&
V_72 >= ( V_59 -> V_63 + V_64 ) )
V_59 = V_59 -> V_65 ;
V_74 = V_59 -> V_63 + V_64 ;
for ( V_75 = V_72 ; V_75 <= V_73 && V_10 == 0 ; V_75 ++ ) {
if ( V_75 >= V_74 && V_59 -> V_65 != NULL ) {
V_59 = V_59 -> V_65 ;
V_74 = V_59 -> V_63 + V_64 ;
}
V_10 = F_26 ( V_59 , V_75 , V_71 ) ;
}
return V_10 ;
}
int F_29 ( void )
{
return ( F_30 ( & V_76 ) > 0 ) ;
}
int F_31 ( struct V_77 * V_78 ,
T_1 V_2 ,
const struct V_79 * V_80 )
{
int V_10 ;
struct V_12 * V_81 ;
F_32 () ;
V_81 = F_33 ( V_80 -> V_1 ) ;
if ( V_81 == NULL ) {
V_10 = - V_48 ;
goto V_82;
}
switch ( V_2 ) {
case V_7 :
switch ( V_81 -> V_22 . type ) {
case V_39 :
V_10 = - V_83 ;
break;
case V_52 :
V_10 = F_34 ( V_78 ,
V_81 -> V_22 . V_51 ,
V_80 ) ;
break;
case V_23 :
V_10 = 0 ;
break;
default:
V_10 = - V_48 ;
}
break;
#if F_9 ( V_32 )
case V_33 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_84 ;
}
V_82:
F_35 () ;
return V_10 ;
}
void F_36 ( struct V_77 * V_78 )
{
F_37 ( V_78 ) ;
}
int F_38 ( struct V_77 * V_78 ,
struct V_79 * V_80 )
{
int V_10 ;
switch ( V_78 -> V_85 ) {
case V_7 :
V_10 = F_39 ( V_78 , V_80 ) ;
break;
#if F_9 ( V_32 )
case V_33 :
V_10 = - V_86 ;
break;
#endif
default:
V_10 = - V_84 ;
}
return V_10 ;
}
int F_40 ( struct V_77 * V_78 ,
struct V_87 * V_3 ,
const struct V_79 * V_80 )
{
int V_10 ;
struct V_88 * V_27 ;
struct V_89 * V_13 ;
F_32 () ;
switch ( V_3 -> V_90 ) {
case V_7 :
V_27 = (struct V_88 * ) V_3 ;
V_13 = F_41 ( V_80 -> V_1 ,
V_27 -> V_91 . V_30 ) ;
if ( V_13 == NULL ) {
V_10 = - V_48 ;
goto V_92;
}
switch ( V_13 -> type ) {
case V_52 :
V_10 = F_34 ( V_78 ,
V_13 -> V_51 , V_80 ) ;
break;
case V_23 :
F_37 ( V_78 ) ;
V_10 = 0 ;
break;
default:
V_10 = - V_48 ;
}
break;
#if F_9 ( V_32 )
case V_33 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_84 ;
}
V_92:
F_35 () ;
return V_10 ;
}
int F_42 ( struct V_93 * V_94 ,
const struct V_79 * V_80 )
{
int V_10 ;
struct V_89 * V_13 ;
F_32 () ;
switch ( V_94 -> V_95 -> V_2 ) {
case V_7 :
V_13 = F_41 ( V_80 -> V_1 ,
F_43 ( V_94 ) -> V_96 ) ;
if ( V_13 == NULL ) {
V_10 = - V_48 ;
goto V_97;
}
switch ( V_13 -> type ) {
case V_52 :
V_10 = F_44 ( V_94 ,
V_13 -> V_51 , V_80 ) ;
break;
case V_23 :
F_45 ( V_94 ) ;
V_10 = 0 ;
break;
default:
V_10 = - V_48 ;
}
break;
#if F_9 ( V_32 )
case V_33 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_84 ;
}
V_97:
F_35 () ;
return V_10 ;
}
void F_46 ( struct V_93 * V_94 )
{
F_45 ( V_94 ) ;
}
int F_47 ( struct V_98 * V_99 ,
T_1 V_2 ,
const struct V_79 * V_80 )
{
int V_10 ;
struct V_100 * V_101 ;
struct V_89 * V_13 ;
F_32 () ;
switch ( V_2 ) {
case V_7 :
V_101 = F_48 ( V_99 ) ;
V_13 = F_41 ( V_80 -> V_1 , V_101 -> V_102 ) ;
if ( V_13 == NULL ) {
V_10 = - V_48 ;
goto V_103;
}
switch ( V_13 -> type ) {
case V_52 :
V_10 = F_49 ( V_99 , V_13 -> V_51 ,
V_80 ) ;
break;
case V_23 :
V_10 = F_50 ( V_99 ) ;
break;
default:
V_10 = - V_48 ;
}
break;
#if F_9 ( V_32 )
case V_33 :
V_10 = 0 ;
break;
#endif
default:
V_10 = - V_84 ;
}
V_103:
F_35 () ;
return V_10 ;
}
int F_51 ( const struct V_98 * V_99 ,
T_1 V_2 ,
struct V_79 * V_80 )
{
switch ( V_2 ) {
case V_7 :
if ( F_52 ( V_99 ) &&
F_53 ( V_99 , V_80 ) == 0 )
return 0 ;
break;
#if F_9 ( V_32 )
case V_33 :
break;
#endif
}
return F_54 ( V_99 , V_2 , V_80 ) ;
}
void F_55 ( struct V_98 * V_99 , int error , int V_104 )
{
if ( F_52 ( V_99 ) )
F_56 ( V_99 , error , V_104 ) ;
}
void F_57 ( void )
{
F_58 () ;
}
int F_59 ( const struct V_98 * V_99 ,
const struct V_79 * V_80 )
{
if ( ( V_80 -> V_71 & V_105 ) == 0 )
return - V_86 ;
if ( F_52 ( V_99 ) )
return F_60 ( V_99 , V_80 ) ;
return - V_86 ;
}
struct V_106 * F_61 ( int type ,
struct V_5 * V_6 )
{
return F_62 ( type , V_6 ) ;
}
static int T_5 F_63 ( void )
{
int V_10 ;
F_64 ( V_107 L_1 ) ;
F_64 ( V_107 L_2 ,
( 1 << V_108 ) ) ;
F_64 ( V_107 L_3
L_4
L_5
L_6 ) ;
V_10 = F_65 ( V_108 ) ;
if ( V_10 != 0 )
goto V_109;
V_10 = F_66 ( V_110 ) ;
if ( V_10 != 0 )
goto V_109;
V_10 = F_67 () ;
if ( V_10 != 0 )
goto V_109;
V_10 = F_68 () ;
if ( V_10 != 0 )
goto V_109;
F_64 ( V_107 L_7 ) ;
return 0 ;
V_109:
F_69 ( L_8 , V_10 ) ;
}
