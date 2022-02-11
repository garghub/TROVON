int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( F_2 ( V_2 == NULL ) )
return - V_4 ;
if ( F_2 ( V_2 -> V_5 >= V_6 ) )
return - V_7 ;
F_3 ( & V_8 ) ;
if ( F_2 ( V_1 [ V_2 -> V_5 ] != NULL ) )
V_3 = - V_9 ;
else
F_4 ( V_1 [ V_2 -> V_5 ] , V_2 ) ;
F_5 ( & V_8 ) ;
return V_3 ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( F_2 ( V_2 == NULL ) )
return - V_4 ;
if ( F_2 ( V_2 -> V_5 >= V_6 ) )
return - V_7 ;
F_3 ( & V_8 ) ;
if ( F_7 ( V_1 [ V_2 -> V_5 ] != NULL ) ) {
if ( F_2 ( V_1 [ V_2 -> V_5 ] != V_2 ) )
V_3 = - V_4 ;
else
F_8 ( V_1 [ V_2 -> V_5 ] , NULL ) ;
}
F_5 ( & V_8 ) ;
F_9 () ;
return V_3 ;
}
static struct V_1 * F_10 ( unsigned int V_5 )
{
struct V_1 * V_2 ;
if ( F_2 ( V_5 >= V_6 ) )
return NULL ;
F_11 () ;
V_2 = F_12 ( V_1 [ V_5 ] ) ;
if ( F_2 ( ! V_2 ) )
F_13 () ;
return V_2 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_13 () ;
}
static int F_15 ( struct V_10 * V_11 , unsigned int V_5 , T_1 V_12 ,
int V_3 )
{
int V_13 ;
struct V_1 * V_2 = F_10 ( V_5 ) ;
if ( ! V_2 )
return - V_7 ;
V_13 = V_2 -> V_14 ( V_11 , V_12 , V_3 ) ;
F_14 ( V_2 ) ;
return V_13 ;
}
void F_16 ( struct V_15 * V_16 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_16 -> V_18 ; V_17 ++ )
F_17 ( V_16 -> V_19 [ V_17 ] ) ;
F_18 ( V_20 , V_16 ) ;
}
struct V_15 * F_19 ( struct V_15 * V_21 )
{
struct V_15 * V_16 ;
V_16 = F_20 ( V_20 , V_22 ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_18 = 0 ;
if ( V_21 ) {
int V_17 ;
memcpy ( V_16 , V_21 , sizeof( * V_16 ) ) ;
for ( V_17 = 0 ; V_17 < V_16 -> V_18 ; V_17 ++ )
F_21 ( V_16 -> V_19 [ V_17 ] ) ;
}
F_22 ( & V_16 -> V_23 , 1 ) ;
return V_16 ;
}
int F_23 ( struct V_10 * V_11 , T_1 V_24 , T_2 * V_25 , T_2 * V_26 )
{
int V_27 , V_28 ;
int V_29 ;
switch ( V_24 ) {
case V_30 :
V_29 = sizeof( struct V_31 ) ;
V_27 = F_24 ( struct V_31 , V_25 ) ;
V_28 = F_24 ( struct V_31 , V_32 ) ;
break;
case V_33 :
V_29 = sizeof( struct V_34 ) ;
V_27 = F_24 ( struct V_34 , V_25 ) ;
V_28 = F_24 ( struct V_34 , V_32 ) ;
break;
case V_35 :
if ( ! F_25 ( V_11 , sizeof( struct V_36 ) ) )
return - V_4 ;
* V_25 = F_26 ( F_27 ( * ( V_37 * ) ( F_28 ( V_11 ) + 2 ) ) ) ;
* V_26 = 0 ;
return 0 ;
default:
return 1 ;
}
if ( ! F_25 ( V_11 , V_29 ) )
return - V_4 ;
* V_25 = * ( T_2 * ) ( F_28 ( V_11 ) + V_27 ) ;
* V_26 = * ( T_2 * ) ( F_28 ( V_11 ) + V_28 ) ;
return 0 ;
}
int F_29 ( struct V_38 * V_39 , struct V_10 * V_11 )
{
struct V_40 * V_41 = V_39 -> V_41 ;
int V_3 ;
V_3 = V_39 -> V_42 -> V_2 -> V_43 ( V_39 , V_11 ) ;
if ( V_3 )
return V_3 ;
if ( V_39 -> V_44 . V_5 == V_45 ) {
V_41 = F_30 ( V_39 , F_31 ( V_11 ) -> V_12 ) ;
if ( V_41 == NULL )
return - V_7 ;
}
V_11 -> V_12 = V_41 -> V_2 -> V_46 ;
return V_41 -> V_47 ( V_39 , V_11 ) ;
}
int F_32 ( struct V_10 * V_11 , int V_24 , T_2 V_25 , int V_48 )
{
struct V_49 * V_49 = F_33 ( V_11 -> V_50 ) ;
int V_3 ;
T_2 V_26 ;
T_2 V_51 ;
struct V_38 * V_39 = NULL ;
T_3 * V_52 ;
struct V_40 * V_41 ;
T_4 V_53 = V_11 -> V_53 ;
unsigned int V_5 ;
int V_54 = 0 ;
int V_55 = 0 ;
if ( V_48 < 0 ) {
V_55 = 1 ;
V_39 = F_34 ( V_11 ) ;
V_26 = F_35 ( V_11 ) -> V_26 . V_56 . V_57 ;
V_5 = V_39 -> V_42 -> V_2 -> V_5 ;
goto V_58;
}
V_52 = ( T_3 * ) ( F_36 ( V_11 ) +
F_37 ( V_11 ) -> V_59 ) ;
V_5 = F_37 ( V_11 ) -> V_5 ;
if ( F_38 ( V_11 ) -> V_60 . V_61 ) {
switch ( V_5 ) {
case V_62 :
V_53 = F_39 ( F_38 ( V_11 ) -> V_60 . V_61 -> V_63 . V_64 ) ;
break;
case V_65 :
V_53 = F_39 ( F_38 ( V_11 ) -> V_60 . V_66 -> V_63 . V_64 ) ;
break;
}
}
if ( ! V_11 -> V_16 || F_40 ( & V_11 -> V_16 -> V_23 ) != 1 ) {
struct V_15 * V_16 ;
V_16 = F_19 ( V_11 -> V_16 ) ;
if ( ! V_16 ) {
F_41 ( V_49 , V_67 ) ;
goto V_68;
}
if ( V_11 -> V_16 )
F_42 ( V_11 -> V_16 ) ;
V_11 -> V_16 = V_16 ;
}
V_26 = 0 ;
if ( ! V_25 && ( V_3 = F_23 ( V_11 , V_24 , & V_25 , & V_26 ) ) != 0 ) {
F_41 ( V_49 , V_69 ) ;
goto V_68;
}
do {
if ( V_11 -> V_16 -> V_18 == V_70 ) {
F_41 ( V_49 , V_71 ) ;
goto V_68;
}
V_39 = F_43 ( V_49 , V_53 , V_52 , V_25 , V_24 , V_5 ) ;
if ( V_39 == NULL ) {
F_41 ( V_49 , V_72 ) ;
F_44 ( V_11 , V_5 , V_25 , V_26 ) ;
goto V_68;
}
V_11 -> V_16 -> V_19 [ V_11 -> V_16 -> V_18 ++ ] = V_39 ;
F_45 ( & V_39 -> V_73 ) ;
if ( F_2 ( V_39 -> V_74 . V_75 != V_76 ) ) {
if ( V_39 -> V_74 . V_75 == V_77 )
F_41 ( V_49 , V_78 ) ;
else
F_41 ( V_49 ,
V_79 ) ;
goto V_80;
}
if ( ( V_39 -> V_81 ? V_39 -> V_81 -> V_48 : 0 ) != V_48 ) {
F_41 ( V_49 , V_82 ) ;
goto V_80;
}
if ( V_39 -> V_83 -> V_84 ( V_39 , V_11 , V_26 ) ) {
F_41 ( V_49 , V_85 ) ;
goto V_80;
}
if ( F_46 ( V_39 ) ) {
F_41 ( V_49 , V_86 ) ;
goto V_80;
}
F_47 ( & V_39 -> V_73 ) ;
if ( F_48 ( V_11 , V_39 , V_5 ) ) {
F_41 ( V_49 , V_87 ) ;
goto V_68;
}
V_51 = F_26 ( F_49 ( V_39 , V_26 ) ) ;
F_35 ( V_11 ) -> V_26 . V_56 . V_57 = V_26 ;
F_35 ( V_11 ) -> V_26 . V_56 . V_88 = V_51 ;
F_50 ( V_11 ) ;
V_24 = V_39 -> type -> V_56 ( V_39 , V_11 ) ;
if ( V_24 == - V_89 )
return 0 ;
V_58:
F_45 ( & V_39 -> V_73 ) ;
if ( V_24 <= 0 ) {
if ( V_24 == - V_90 ) {
F_51 ( V_39 , V_11 ,
V_39 -> type -> V_91 ) ;
V_39 -> V_92 . V_93 ++ ;
}
F_41 ( V_49 , V_94 ) ;
goto V_80;
}
V_48 = 0 ;
if ( V_55 && V_39 -> V_83 -> V_95 ( V_39 , V_11 , V_26 ) ) {
F_41 ( V_49 , V_85 ) ;
goto V_80;
}
V_39 -> V_83 -> V_96 ( V_39 , V_26 ) ;
V_39 -> V_97 . V_98 += V_11 -> V_18 ;
V_39 -> V_97 . V_99 ++ ;
F_47 ( & V_39 -> V_73 ) ;
F_31 ( V_11 ) -> V_12 = V_24 ;
V_41 = V_39 -> V_41 ;
if ( V_39 -> V_44 . V_5 == V_45 ) {
V_41 = F_30 ( V_39 , F_31 ( V_11 ) -> V_12 ) ;
if ( V_41 == NULL ) {
F_41 ( V_49 , V_87 ) ;
goto V_68;
}
}
if ( V_41 -> V_56 ( V_39 , V_11 ) ) {
F_41 ( V_49 , V_87 ) ;
goto V_68;
}
if ( V_39 -> V_42 -> V_100 & V_101 ) {
V_54 = 1 ;
break;
}
V_52 = & V_39 -> V_102 . V_52 ;
V_5 = V_39 -> V_42 -> V_2 -> V_5 ;
V_3 = F_23 ( V_11 , V_24 , & V_25 , & V_26 ) ;
if ( V_3 < 0 ) {
F_41 ( V_49 , V_69 ) ;
goto V_68;
}
} while ( ! V_3 );
V_3 = F_15 ( V_11 , V_5 , V_39 -> type -> V_91 , 0 ) ;
if ( V_3 )
goto V_68;
F_52 ( V_11 ) ;
if ( V_54 ) {
F_53 ( V_11 ) ;
F_54 ( V_11 ) ;
return 0 ;
} else {
return V_39 -> V_41 -> V_2 -> V_103 ( V_11 , V_55 ) ;
}
V_80:
F_47 ( & V_39 -> V_73 ) ;
V_68:
F_15 ( V_11 , V_5 , V_39 && V_39 -> type ? V_39 -> type -> V_91 : V_24 , - 1 ) ;
F_55 ( V_11 ) ;
return 0 ;
}
int F_56 ( struct V_10 * V_11 , int V_24 )
{
return F_32 ( V_11 , V_24 , 0 , - 1 ) ;
}
void T_5 F_57 ( void )
{
V_20 = F_58 ( L_1 ,
sizeof( struct V_15 ) ,
0 , V_104 | V_105 ,
NULL ) ;
}
