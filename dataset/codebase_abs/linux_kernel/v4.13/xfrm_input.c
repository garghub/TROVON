int F_1 ( const struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( F_2 ( V_2 -> V_4 >= F_3 ( V_1 ) ) )
return - V_5 ;
F_4 ( & V_6 ) ;
if ( F_5 ( V_1 [ V_2 -> V_4 ] != NULL ) )
V_3 = - V_7 ;
else
F_6 ( V_1 [ V_2 -> V_4 ] , V_2 ) ;
F_7 ( & V_6 ) ;
return V_3 ;
}
int F_8 ( const struct V_1 * V_2 )
{
int V_3 = 0 ;
F_4 ( & V_6 ) ;
if ( F_9 ( V_1 [ V_2 -> V_4 ] != NULL ) ) {
if ( F_5 ( V_1 [ V_2 -> V_4 ] != V_2 ) )
V_3 = - V_8 ;
else
F_10 ( V_1 [ V_2 -> V_4 ] , NULL ) ;
}
F_7 ( & V_6 ) ;
F_11 () ;
return V_3 ;
}
static const struct V_1 * F_12 ( unsigned int V_4 )
{
const struct V_1 * V_2 ;
if ( F_13 ( V_4 >= F_3 ( V_1 ) ) )
return NULL ;
F_14 () ;
V_2 = F_15 ( V_1 [ V_4 ] ) ;
if ( F_5 ( ! V_2 ) )
F_16 () ;
return V_2 ;
}
static int F_17 ( struct V_9 * V_10 , unsigned int V_4 , T_1 V_11 ,
int V_3 )
{
int V_12 ;
const struct V_1 * V_2 = F_12 ( V_4 ) ;
if ( ! V_2 )
return - V_5 ;
V_12 = V_2 -> V_13 ( V_10 , V_11 , V_3 ) ;
F_16 () ;
return V_12 ;
}
void F_18 ( struct V_14 * V_15 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_15 -> V_17 ; V_16 ++ )
F_19 ( V_15 -> V_18 [ V_16 ] ) ;
F_20 ( V_19 , V_15 ) ;
}
struct V_14 * F_21 ( struct V_14 * V_20 )
{
struct V_14 * V_15 ;
V_15 = F_22 ( V_19 , V_21 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_17 = 0 ;
V_15 -> V_22 = 0 ;
memset ( V_15 -> V_23 , 0 , sizeof( V_15 -> V_23 [ V_24 ] ) ) ;
if ( V_20 ) {
int V_16 ;
memcpy ( V_15 , V_20 , sizeof( * V_15 ) ) ;
for ( V_16 = 0 ; V_16 < V_15 -> V_17 ; V_16 ++ )
F_23 ( V_15 -> V_18 [ V_16 ] ) ;
}
F_24 ( & V_15 -> V_25 , 1 ) ;
return V_15 ;
}
int F_25 ( struct V_9 * V_10 )
{
struct V_14 * V_15 ;
if ( ! V_10 -> V_15 || F_26 ( & V_10 -> V_15 -> V_25 ) != 1 ) {
V_15 = F_21 ( V_10 -> V_15 ) ;
if ( ! V_15 )
return - V_26 ;
if ( V_10 -> V_15 )
F_27 ( V_10 -> V_15 ) ;
V_10 -> V_15 = V_15 ;
}
return 0 ;
}
int F_28 ( struct V_9 * V_10 , T_1 V_27 , T_2 * V_28 , T_2 * V_29 )
{
int V_30 , V_31 ;
int V_32 ;
switch ( V_27 ) {
case V_33 :
V_32 = sizeof( struct V_34 ) ;
V_30 = F_29 ( struct V_34 , V_28 ) ;
V_31 = F_29 ( struct V_34 , V_35 ) ;
break;
case V_36 :
V_32 = sizeof( struct V_37 ) ;
V_30 = F_29 ( struct V_37 , V_28 ) ;
V_31 = F_29 ( struct V_37 , V_35 ) ;
break;
case V_38 :
if ( ! F_30 ( V_10 , sizeof( struct V_39 ) ) )
return - V_8 ;
* V_28 = F_31 ( F_32 ( * ( V_40 * ) ( F_33 ( V_10 ) + 2 ) ) ) ;
* V_29 = 0 ;
return 0 ;
default:
return 1 ;
}
if ( ! F_30 ( V_10 , V_32 ) )
return - V_8 ;
* V_28 = * ( T_2 * ) ( F_33 ( V_10 ) + V_30 ) ;
* V_29 = * ( T_2 * ) ( F_33 ( V_10 ) + V_31 ) ;
return 0 ;
}
int F_34 ( struct V_41 * V_42 , struct V_9 * V_10 )
{
struct V_43 * V_44 = V_42 -> V_44 ;
int V_3 ;
V_3 = V_42 -> V_45 -> V_2 -> V_46 ( V_42 , V_10 ) ;
if ( V_3 )
return V_3 ;
if ( V_42 -> V_47 . V_4 == V_48 ) {
V_44 = F_35 ( V_42 , F_36 ( V_10 ) -> V_11 ) ;
if ( V_44 == NULL )
return - V_5 ;
}
V_10 -> V_11 = V_44 -> V_2 -> V_49 ;
return V_44 -> V_50 ( V_42 , V_10 ) ;
}
int F_37 ( struct V_9 * V_10 , int V_27 , T_2 V_28 , int V_51 )
{
struct V_52 * V_52 = F_38 ( V_10 -> V_53 ) ;
int V_3 ;
T_2 V_29 ;
T_2 V_54 ;
struct V_41 * V_42 = NULL ;
T_3 * V_55 ;
struct V_43 * V_44 ;
T_4 V_56 = V_10 -> V_56 ;
unsigned int V_4 ;
int V_57 = 0 ;
int V_58 = 0 ;
bool V_59 = false ;
bool V_60 = false ;
struct V_61 * V_62 = V_61 ( V_10 ) ;
if ( V_51 < 0 ) {
V_42 = F_39 ( V_10 ) ;
V_4 = V_42 -> V_45 -> V_2 -> V_4 ;
if ( V_51 == - 1 ) {
V_58 = 1 ;
V_29 = F_40 ( V_10 ) -> V_29 . V_63 . V_64 ;
goto V_65;
}
V_51 = 0 ;
V_29 = F_41 ( V_10 ) -> V_29 ;
if ( V_62 && ( V_62 -> V_66 & V_67 ) ) {
V_60 = true ;
V_42 = F_39 ( V_10 ) ;
V_4 = F_41 ( V_10 ) -> V_4 ;
if ( ! ( V_62 -> V_68 & V_69 ) ) {
if ( V_62 -> V_68 &
( V_70 |
V_71 |
V_72 |
V_73 ) ) {
F_42 ( V_42 , V_10 ,
V_42 -> type -> V_74 ) ;
V_42 -> V_75 . V_76 ++ ;
F_43 ( V_52 , V_77 ) ;
goto V_78;
}
F_43 ( V_52 , V_79 ) ;
goto V_78;
}
if ( ( V_3 = F_28 ( V_10 , V_27 , & V_28 , & V_29 ) ) != 0 ) {
F_43 ( V_52 , V_80 ) ;
goto V_78;
}
}
goto V_81;
}
V_55 = ( T_3 * ) ( F_44 ( V_10 ) +
F_41 ( V_10 ) -> V_82 ) ;
V_4 = F_41 ( V_10 ) -> V_4 ;
switch ( V_4 ) {
case V_83 :
if ( F_45 ( V_10 ) -> V_84 . V_85 )
V_56 = F_46 ( F_45 ( V_10 ) -> V_84 . V_85 -> V_86 . V_87 ) ;
break;
case V_88 :
if ( F_45 ( V_10 ) -> V_84 . V_89 )
V_56 = F_46 ( F_45 ( V_10 ) -> V_84 . V_89 -> V_86 . V_87 ) ;
break;
}
V_3 = F_25 ( V_10 ) ;
if ( V_3 ) {
F_43 ( V_52 , V_90 ) ;
goto V_78;
}
V_29 = 0 ;
if ( ! V_28 && ( V_3 = F_28 ( V_10 , V_27 , & V_28 , & V_29 ) ) != 0 ) {
F_43 ( V_52 , V_80 ) ;
goto V_78;
}
do {
if ( V_10 -> V_15 -> V_17 == V_91 ) {
F_43 ( V_52 , V_79 ) ;
goto V_78;
}
V_42 = F_47 ( V_52 , V_56 , V_55 , V_28 , V_27 , V_4 ) ;
if ( V_42 == NULL ) {
F_43 ( V_52 , V_92 ) ;
F_48 ( V_10 , V_4 , V_28 , V_29 ) ;
goto V_78;
}
V_10 -> V_15 -> V_18 [ V_10 -> V_15 -> V_17 ++ ] = V_42 ;
V_81:
F_49 ( & V_42 -> V_81 ) ;
if ( F_5 ( V_42 -> V_93 . V_94 != V_95 ) ) {
if ( V_42 -> V_93 . V_94 == V_96 )
F_43 ( V_52 , V_97 ) ;
else
F_43 ( V_52 ,
V_98 ) ;
goto V_99;
}
if ( ( V_42 -> V_100 ? V_42 -> V_100 -> V_51 : 0 ) != V_51 ) {
F_43 ( V_52 , V_101 ) ;
goto V_99;
}
if ( V_42 -> V_102 -> V_103 ( V_42 , V_10 , V_29 ) ) {
F_43 ( V_52 , V_104 ) ;
goto V_99;
}
if ( F_50 ( V_42 ) ) {
F_43 ( V_52 , V_105 ) ;
goto V_99;
}
F_51 ( & V_42 -> V_81 ) ;
if ( F_52 ( V_10 , V_42 , V_4 ) ) {
F_43 ( V_52 , V_106 ) ;
goto V_78;
}
V_54 = F_31 ( F_53 ( V_42 , V_29 ) ) ;
F_40 ( V_10 ) -> V_29 . V_63 . V_64 = V_29 ;
F_40 ( V_10 ) -> V_29 . V_63 . V_107 = V_54 ;
F_54 ( V_10 ) ;
F_55 ( V_10 -> V_53 ) ;
if ( V_60 )
V_27 = V_42 -> V_108 -> V_109 ( V_42 , V_10 ) ;
else
V_27 = V_42 -> type -> V_63 ( V_42 , V_10 ) ;
if ( V_27 == - V_110 )
return 0 ;
V_65:
F_56 ( V_10 -> V_53 ) ;
F_49 ( & V_42 -> V_81 ) ;
if ( V_27 <= 0 ) {
if ( V_27 == - V_111 ) {
F_42 ( V_42 , V_10 ,
V_42 -> type -> V_74 ) ;
V_42 -> V_75 . V_76 ++ ;
}
F_43 ( V_52 , V_77 ) ;
goto V_99;
}
V_51 = 0 ;
if ( V_58 && V_42 -> V_102 -> V_112 ( V_42 , V_10 , V_29 ) ) {
F_43 ( V_52 , V_104 ) ;
goto V_99;
}
V_42 -> V_102 -> V_113 ( V_42 , V_29 ) ;
V_42 -> V_114 . V_115 += V_10 -> V_17 ;
V_42 -> V_114 . V_116 ++ ;
F_51 ( & V_42 -> V_81 ) ;
F_36 ( V_10 ) -> V_11 = V_27 ;
V_44 = V_42 -> V_44 ;
if ( V_42 -> V_47 . V_4 == V_48 ) {
V_44 = F_35 ( V_42 , F_36 ( V_10 ) -> V_11 ) ;
if ( V_44 == NULL ) {
F_43 ( V_52 , V_106 ) ;
goto V_78;
}
}
if ( V_44 -> V_63 ( V_42 , V_10 ) ) {
F_43 ( V_52 , V_106 ) ;
goto V_78;
}
if ( V_42 -> V_45 -> V_66 & V_117 ) {
V_57 = 1 ;
break;
}
V_55 = & V_42 -> V_118 . V_55 ;
V_4 = V_42 -> V_45 -> V_2 -> V_4 ;
V_3 = F_28 ( V_10 , V_27 , & V_28 , & V_29 ) ;
if ( V_3 < 0 ) {
F_43 ( V_52 , V_80 ) ;
goto V_78;
}
} while ( ! V_3 );
V_3 = F_17 ( V_10 , V_4 , V_42 -> type -> V_74 , 0 ) ;
if ( V_3 )
goto V_78;
F_57 ( V_10 ) ;
if ( V_57 ) {
F_58 ( V_10 ) ;
F_59 ( & V_119 , V_10 ) ;
return 0 ;
} else {
V_62 = V_61 ( V_10 ) ;
if ( V_62 )
V_59 = V_62 -> V_66 & V_120 ;
V_3 = V_42 -> V_44 -> V_2 -> V_121 ( V_10 , V_59 || V_58 ) ;
if ( V_59 ) {
F_58 ( V_10 ) ;
F_59 ( & V_119 , V_10 ) ;
return V_3 ;
}
return V_3 ;
}
V_99:
F_51 ( & V_42 -> V_81 ) ;
V_78:
F_17 ( V_10 , V_4 , V_42 && V_42 -> type ? V_42 -> type -> V_74 : V_27 , - 1 ) ;
F_60 ( V_10 ) ;
return 0 ;
}
int F_61 ( struct V_9 * V_10 , int V_27 )
{
return F_37 ( V_10 , V_27 , 0 , - 1 ) ;
}
void T_5 F_62 ( void )
{
int V_3 ;
F_63 ( & V_122 ) ;
V_3 = F_64 ( & V_119 , & V_122 ) ;
if ( V_3 )
V_119 . V_123 = NULL ;
V_19 = F_65 ( L_1 ,
sizeof( struct V_14 ) ,
0 , V_124 | V_125 ,
NULL ) ;
}
