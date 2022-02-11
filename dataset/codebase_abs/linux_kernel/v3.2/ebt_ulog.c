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
V_5 = F_11 ( V_17 , V_12 | V_19 ) ;
if ( ! V_5 ) {
if ( V_17 > V_16 ) {
V_5 = F_11 ( V_16 , V_12 ) ;
if ( ! V_5 )
F_12 ( L_1 ,
V_16 ) ;
}
}
return V_5 ;
}
static void F_13 ( unsigned int V_20 , const struct V_15 * V_5 ,
const struct V_21 * V_22 , const struct V_21 * V_23 ,
const struct V_24 * V_25 , const char * V_26 )
{
T_2 * V_27 ;
T_3 V_16 , V_28 ;
struct V_29 * V_30 ;
unsigned int V_31 = V_25 -> V_1 ;
T_1 * V_2 = & V_3 [ V_31 ] ;
T_4 * V_14 = & V_2 -> V_14 ;
T_5 V_32 ;
if ( ( V_25 -> V_33 == 0 ) ||
( V_25 -> V_33 > V_5 -> V_34 + V_35 ) )
V_28 = V_5 -> V_34 + V_35 ;
else
V_28 = V_25 -> V_33 ;
V_16 = F_14 ( sizeof( * V_27 ) + V_28 ) ;
if ( V_16 > V_18 ) {
F_12 ( L_2 , V_16 , V_18 ) ;
return;
}
F_7 ( V_14 ) ;
if ( ! V_2 -> V_5 ) {
if ( ! ( V_2 -> V_5 = F_9 ( V_16 ) ) )
goto V_36;
} else if ( V_16 > F_15 ( V_2 -> V_5 ) ) {
F_1 ( V_31 ) ;
if ( ! ( V_2 -> V_5 = F_9 ( V_16 ) ) )
goto V_36;
}
V_30 = F_16 ( V_2 -> V_5 , 0 , V_2 -> V_6 , 0 ,
V_16 - F_17 ( sizeof( * V_30 ) ) ) ;
V_2 -> V_6 ++ ;
V_27 = F_18 ( V_30 ) ;
V_27 -> V_37 = V_38 ;
V_32 = F_19 () ;
V_27 -> V_39 = F_20 ( V_32 ) ;
if ( V_2 -> V_6 == 1 )
V_2 -> V_5 -> V_40 = V_32 ;
V_27 -> V_41 = V_28 ;
V_27 -> V_42 = V_5 -> V_42 ;
V_27 -> V_43 = V_20 ;
if ( V_25 -> V_26 != NULL )
strcpy ( V_27 -> V_26 , V_25 -> V_26 ) ;
else
* ( V_27 -> V_26 ) = '\0' ;
if ( V_22 ) {
strcpy ( V_27 -> V_44 , V_22 -> V_45 ) ;
if ( F_21 ( V_22 ) )
strcpy ( V_27 -> V_46 , F_22 ( V_22 ) -> V_47 -> V_48 -> V_45 ) ;
else
strcpy ( V_27 -> V_46 , V_22 -> V_45 ) ;
} else
V_27 -> V_46 [ 0 ] = V_27 -> V_44 [ 0 ] = '\0' ;
if ( V_23 ) {
strcpy ( V_27 -> V_49 , V_23 -> V_45 ) ;
strcpy ( V_27 -> V_50 , F_22 ( V_23 ) -> V_47 -> V_48 -> V_45 ) ;
} else
V_27 -> V_50 [ 0 ] = V_27 -> V_49 [ 0 ] = '\0' ;
if ( F_23 ( V_5 , - V_35 , V_27 -> V_13 , V_28 ) < 0 )
F_24 () ;
if ( V_2 -> V_6 > 1 )
V_2 -> V_7 -> V_51 |= V_52 ;
V_2 -> V_7 = V_30 ;
if ( V_2 -> V_6 >= V_25 -> V_53 )
F_1 ( V_31 ) ;
else if ( ! F_2 ( & V_2 -> V_4 ) ) {
V_2 -> V_4 . V_54 = V_55 + V_56 * V_57 / 100 ;
F_25 ( & V_2 -> V_4 ) ;
}
V_58:
F_8 ( V_14 ) ;
return;
V_59:
F_12 ( L_3
L_4 ) ;
V_36:
goto V_58;
}
static void F_26 ( T_6 V_60 , unsigned int V_61 ,
const struct V_15 * V_5 , const struct V_21 * V_22 ,
const struct V_21 * V_23 , const struct V_62 * V_63 ,
const char * V_26 )
{
struct V_24 V_64 ;
if ( ! V_63 || V_63 -> type != V_65 ) {
V_64 . V_1 = V_66 ;
V_64 . V_33 = 0 ;
V_64 . V_53 = V_67 ;
V_64 . V_26 [ 0 ] = '\0' ;
} else {
V_64 . V_1 = V_63 -> V_68 . V_69 . V_31 ;
V_64 . V_33 = V_63 -> V_68 . V_69 . V_28 ;
V_64 . V_53 = V_63 -> V_68 . V_69 . V_53 ;
F_27 ( V_64 . V_26 , V_26 , sizeof( V_64 . V_26 ) ) ;
}
F_13 ( V_61 , V_5 , V_22 , V_23 , & V_64 , V_26 ) ;
}
static unsigned int
F_28 ( struct V_15 * V_5 , const struct V_70 * V_71 )
{
F_13 ( V_71 -> V_61 , V_5 , V_71 -> V_22 , V_71 -> V_23 ,
V_71 -> V_72 , NULL ) ;
return V_73 ;
}
static int F_29 ( const struct V_74 * V_71 )
{
struct V_24 * V_25 = V_71 -> V_72 ;
if ( V_25 -> V_1 > 31 )
return - V_75 ;
V_25 -> V_26 [ V_76 - 1 ] = '\0' ;
if ( V_25 -> V_53 > V_77 )
V_25 -> V_53 = V_77 ;
return 0 ;
}
static int T_7 F_30 ( void )
{
int V_78 ;
int V_79 ;
if ( V_18 >= 128 * 1024 ) {
F_31 ( L_5
L_6 ) ;
return - V_75 ;
}
for ( V_79 = 0 ; V_79 < V_80 ; V_79 ++ ) {
F_32 ( & V_3 [ V_79 ] . V_4 , F_6 , V_79 ) ;
F_33 ( & V_3 [ V_79 ] . V_14 ) ;
}
V_11 = F_34 ( & V_81 , V_82 ,
V_80 , NULL , NULL ,
V_83 ) ;
if ( ! V_11 )
V_78 = - V_84 ;
else if ( ( V_78 = F_35 ( & V_85 ) ) != 0 )
F_36 ( V_11 ) ;
if ( V_78 == 0 )
F_37 ( V_86 , & V_87 ) ;
return V_78 ;
}
static void T_8 F_38 ( void )
{
T_1 * V_2 ;
int V_79 ;
F_39 ( & V_87 ) ;
F_40 ( & V_85 ) ;
for ( V_79 = 0 ; V_79 < V_80 ; V_79 ++ ) {
V_2 = & V_3 [ V_79 ] ;
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
