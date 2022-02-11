static void F_1 ( unsigned int V_1 )
{
T_1 * V_2 = & V_3 [ V_1 ] ;
if ( F_2 ( & V_2 -> V_4 ) )
F_3 ( & V_2 -> V_4 ) ;
if ( ! V_2 -> V_5 )
return;
if ( V_2 -> V_6 > 1 )
V_2 -> V_7 -> V_8 = V_9 ;
F_4 ( V_2 -> V_5 ) . V_10 = V_1 + 1 ;
F_5 ( V_11 , V_2 -> V_5 , 0 , V_1 + 1 , V_12 ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_5 = NULL ;
}
static void F_6 ( unsigned long V_13 )
{
F_7 ( & V_3 [ V_13 ] . V_14 ) ;
if ( V_3 [ V_13 ] . V_5 )
F_1 ( V_13 ) ;
F_8 ( & V_3 [ V_13 ] . V_14 ) ;
}
static struct V_15 * F_9 ( unsigned int V_16 )
{
struct V_15 * V_5 ;
unsigned int V_17 ;
V_17 = F_10 ( V_16 , V_18 ) ;
V_5 = F_11 ( V_17 , V_12 ) ;
if ( ! V_5 ) {
F_12 ( L_1 , V_17 ) ;
if ( V_17 > V_16 ) {
V_5 = F_11 ( V_16 , V_12 ) ;
if ( ! V_5 )
F_12 ( L_2
L_3 , V_16 ) ;
}
}
return V_5 ;
}
static void F_13 ( unsigned int V_19 , const struct V_15 * V_5 ,
const struct V_20 * V_21 , const struct V_20 * V_22 ,
const struct V_23 * V_24 , const char * V_25 )
{
T_2 * V_26 ;
T_3 V_16 , V_27 ;
struct V_28 * V_29 ;
unsigned int V_30 = V_24 -> V_1 ;
T_1 * V_2 = & V_3 [ V_30 ] ;
T_4 * V_14 = & V_2 -> V_14 ;
T_5 V_31 ;
if ( ( V_24 -> V_32 == 0 ) ||
( V_24 -> V_32 > V_5 -> V_33 + V_34 ) )
V_27 = V_5 -> V_33 + V_34 ;
else
V_27 = V_24 -> V_32 ;
V_16 = F_14 ( sizeof( * V_26 ) + V_27 ) ;
if ( V_16 > V_18 ) {
F_12 ( L_4 , V_16 , V_18 ) ;
return;
}
F_7 ( V_14 ) ;
if ( ! V_2 -> V_5 ) {
if ( ! ( V_2 -> V_5 = F_9 ( V_16 ) ) )
goto V_35;
} else if ( V_16 > F_15 ( V_2 -> V_5 ) ) {
F_1 ( V_30 ) ;
if ( ! ( V_2 -> V_5 = F_9 ( V_16 ) ) )
goto V_35;
}
V_29 = F_16 ( V_2 -> V_5 , 0 , V_2 -> V_6 , 0 ,
V_16 - F_17 ( sizeof( * V_29 ) ) ) ;
V_2 -> V_6 ++ ;
V_26 = F_18 ( V_29 ) ;
V_26 -> V_36 = V_37 ;
V_31 = F_19 () ;
V_26 -> V_38 = F_20 ( V_31 ) ;
if ( V_2 -> V_6 == 1 )
V_2 -> V_5 -> V_39 = V_31 ;
V_26 -> V_40 = V_27 ;
V_26 -> V_41 = V_5 -> V_41 ;
V_26 -> V_42 = V_19 ;
if ( V_24 -> V_25 != NULL )
strcpy ( V_26 -> V_25 , V_24 -> V_25 ) ;
else
* ( V_26 -> V_25 ) = '\0' ;
if ( V_21 ) {
strcpy ( V_26 -> V_43 , V_21 -> V_44 ) ;
if ( F_21 ( V_21 ) )
strcpy ( V_26 -> V_45 , F_22 ( V_21 ) -> V_46 -> V_47 -> V_44 ) ;
else
strcpy ( V_26 -> V_45 , V_21 -> V_44 ) ;
} else
V_26 -> V_45 [ 0 ] = V_26 -> V_43 [ 0 ] = '\0' ;
if ( V_22 ) {
strcpy ( V_26 -> V_48 , V_22 -> V_44 ) ;
strcpy ( V_26 -> V_49 , F_22 ( V_22 ) -> V_46 -> V_47 -> V_44 ) ;
} else
V_26 -> V_49 [ 0 ] = V_26 -> V_48 [ 0 ] = '\0' ;
if ( F_23 ( V_5 , - V_34 , V_26 -> V_13 , V_27 ) < 0 )
F_24 () ;
if ( V_2 -> V_6 > 1 )
V_2 -> V_7 -> V_50 |= V_51 ;
V_2 -> V_7 = V_29 ;
if ( V_2 -> V_6 >= V_24 -> V_52 )
F_1 ( V_30 ) ;
else if ( ! F_2 ( & V_2 -> V_4 ) ) {
V_2 -> V_4 . V_53 = V_54 + V_55 * V_56 / 100 ;
F_25 ( & V_2 -> V_4 ) ;
}
V_57:
F_8 ( V_14 ) ;
return;
V_58:
F_12 ( L_5
L_6 ) ;
goto V_57;
V_35:
goto V_57;
}
static void F_26 ( T_6 V_59 , unsigned int V_60 ,
const struct V_15 * V_5 , const struct V_20 * V_21 ,
const struct V_20 * V_22 , const struct V_61 * V_62 ,
const char * V_25 )
{
struct V_23 V_63 ;
if ( ! V_62 || V_62 -> type != V_64 ) {
V_63 . V_1 = V_65 ;
V_63 . V_32 = 0 ;
V_63 . V_52 = V_66 ;
V_63 . V_25 [ 0 ] = '\0' ;
} else {
V_63 . V_1 = V_62 -> V_67 . V_68 . V_30 ;
V_63 . V_32 = V_62 -> V_67 . V_68 . V_27 ;
V_63 . V_52 = V_62 -> V_67 . V_68 . V_52 ;
F_27 ( V_63 . V_25 , V_25 , sizeof( V_63 . V_25 ) ) ;
}
F_13 ( V_60 , V_5 , V_21 , V_22 , & V_63 , V_25 ) ;
}
static unsigned int
F_28 ( struct V_15 * V_5 , const struct V_69 * V_70 )
{
F_13 ( V_70 -> V_60 , V_5 , V_70 -> V_21 , V_70 -> V_22 ,
V_70 -> V_71 , NULL ) ;
return V_72 ;
}
static int F_29 ( const struct V_73 * V_70 )
{
struct V_23 * V_24 = V_70 -> V_71 ;
if ( V_24 -> V_1 > 31 )
return - V_74 ;
V_24 -> V_25 [ V_75 - 1 ] = '\0' ;
if ( V_24 -> V_52 > V_76 )
V_24 -> V_52 = V_76 ;
return 0 ;
}
static int T_7 F_30 ( void )
{
int V_77 ;
int V_78 ;
if ( V_18 >= 128 * 1024 ) {
F_31 ( L_7
L_8 ) ;
return - V_74 ;
}
for ( V_78 = 0 ; V_78 < V_79 ; V_78 ++ ) {
F_32 ( & V_3 [ V_78 ] . V_4 , F_6 , V_78 ) ;
F_33 ( & V_3 [ V_78 ] . V_14 ) ;
}
V_11 = F_34 ( & V_80 , V_81 ,
V_79 , NULL , NULL ,
V_82 ) ;
if ( ! V_11 )
V_77 = - V_83 ;
else if ( ( V_77 = F_35 ( & V_84 ) ) != 0 )
F_36 ( V_11 ) ;
if ( V_77 == 0 )
F_37 ( V_85 , & V_86 ) ;
return V_77 ;
}
static void T_8 F_38 ( void )
{
T_1 * V_2 ;
int V_78 ;
F_39 ( & V_86 ) ;
F_40 ( & V_84 ) ;
for ( V_78 = 0 ; V_78 < V_79 ; V_78 ++ ) {
V_2 = & V_3 [ V_78 ] ;
if ( F_2 ( & V_2 -> V_4 ) )
F_3 ( & V_2 -> V_4 ) ;
F_7 ( & V_2 -> V_14 ) ;
if ( V_2 -> V_5 ) {
F_41 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
F_8 ( & V_2 -> V_14 ) ;
}
F_36 ( V_11 ) ;
}
