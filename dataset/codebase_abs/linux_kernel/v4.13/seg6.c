bool F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
unsigned int V_5 ;
if ( V_2 -> type != V_6 )
return false ;
if ( ( ( V_2 -> V_7 + 1 ) << 3 ) != V_3 )
return false ;
if ( V_2 -> V_8 != V_2 -> V_9 )
return false ;
V_5 = sizeof( * V_2 ) + ( ( V_2 -> V_9 + 1 ) << 4 ) ;
V_4 = V_3 - V_5 ;
if ( V_4 < 0 )
return false ;
while ( V_4 ) {
struct V_10 * V_11 ;
unsigned int V_12 ;
if ( V_4 < sizeof( * V_11 ) )
return false ;
V_11 = (struct V_10 * ) ( ( unsigned char * ) V_2 + V_5 ) ;
V_12 = sizeof( * V_11 ) + V_11 -> V_3 ;
V_4 -= V_12 ;
if ( V_4 < 0 )
return false ;
V_5 += V_12 ;
}
return true ;
}
static int F_2 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_17 * V_17 = F_3 ( V_16 ) ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
T_1 V_22 ;
char * V_23 ;
int V_24 = 0 ;
T_2 V_25 ;
T_2 V_26 ;
V_19 = F_4 ( V_17 ) ;
if ( ! V_16 -> V_27 [ V_28 ] ||
! V_16 -> V_27 [ V_29 ] ||
! V_16 -> V_27 [ V_30 ] )
return - V_31 ;
V_22 = F_5 ( V_16 -> V_27 [ V_28 ] ) ;
V_26 = F_6 ( V_16 -> V_27 [ V_29 ] ) ;
V_25 = F_6 ( V_16 -> V_27 [ V_30 ] ) ;
if ( V_22 == 0 )
return - V_31 ;
if ( V_26 > V_32 )
return - V_31 ;
F_7 ( & V_19 -> V_33 ) ;
V_21 = F_8 ( V_17 , V_22 ) ;
if ( ! V_26 ) {
if ( ! V_21 )
V_24 = - V_34 ;
V_24 = F_9 ( V_17 , V_22 ) ;
goto V_35;
}
if ( ! V_16 -> V_27 [ V_36 ] ) {
V_24 = - V_31 ;
goto V_35;
}
if ( V_21 ) {
V_24 = F_9 ( V_17 , V_22 ) ;
if ( V_24 )
goto V_35;
}
V_23 = ( char * ) F_10 ( V_16 -> V_27 [ V_36 ] ) ;
V_21 = F_11 ( sizeof( * V_21 ) , V_37 ) ;
if ( ! V_21 ) {
V_24 = - V_38 ;
goto V_35;
}
memcpy ( V_21 -> V_23 , V_23 , V_26 ) ;
V_21 -> V_26 = V_26 ;
V_21 -> V_39 = V_25 ;
V_21 -> V_22 = V_22 ;
V_24 = F_12 ( V_17 , V_22 , V_21 ) ;
if ( V_24 )
F_13 ( V_21 ) ;
V_35:
F_14 ( & V_19 -> V_33 ) ;
return V_24 ;
}
static int F_2 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
return - V_40 ;
}
static int F_15 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_17 * V_17 = F_3 ( V_16 ) ;
struct V_41 * V_42 , * V_43 , * V_44 ;
struct V_18 * V_19 ;
V_19 = F_4 ( V_17 ) ;
if ( ! V_16 -> V_27 [ V_45 ] )
return - V_31 ;
V_42 = F_10 ( V_16 -> V_27 [ V_45 ] ) ;
V_44 = F_16 ( V_42 , sizeof( * V_42 ) , V_37 ) ;
if ( ! V_44 )
return - V_38 ;
F_7 ( & V_19 -> V_33 ) ;
V_43 = V_19 -> V_46 ;
F_17 ( V_19 -> V_46 , V_44 ) ;
F_14 ( & V_19 -> V_33 ) ;
F_18 () ;
F_13 ( V_43 ) ;
return 0 ;
}
static int F_19 ( struct V_13 * V_14 , struct V_15 * V_16 )
{
struct V_17 * V_17 = F_3 ( V_16 ) ;
struct V_41 * V_46 ;
struct V_13 * V_47 ;
void * V_48 ;
V_47 = F_20 ( V_49 , V_37 ) ;
if ( ! V_47 )
return - V_38 ;
V_48 = F_21 ( V_47 , V_16 -> V_50 , V_16 -> V_51 ,
& V_52 , 0 , V_53 ) ;
if ( ! V_48 )
goto V_54;
F_22 () ;
V_46 = F_23 ( F_4 ( V_17 ) -> V_46 ) ;
if ( F_24 ( V_47 , V_45 , sizeof( struct V_41 ) , V_46 ) )
goto V_55;
F_25 () ;
F_26 ( V_47 , V_48 ) ;
F_27 ( V_47 , V_16 ) ;
return 0 ;
V_55:
F_25 () ;
F_28 ( V_47 , V_48 ) ;
V_54:
F_29 ( V_47 ) ;
return - V_38 ;
}
static int F_30 ( struct V_20 * V_21 ,
struct V_13 * V_47 )
{
if ( F_31 ( V_47 , V_28 , V_21 -> V_22 ) ||
F_32 ( V_47 , V_29 , V_21 -> V_26 ) ||
F_24 ( V_47 , V_36 , V_21 -> V_26 , V_21 -> V_23 ) ||
F_32 ( V_47 , V_30 , V_21 -> V_39 ) )
return - 1 ;
return 0 ;
}
static int F_33 ( struct V_20 * V_21 ,
T_1 V_56 , T_1 V_57 , T_1 V_58 ,
struct V_13 * V_14 , T_2 V_59 )
{
void * V_48 ;
V_48 = F_21 ( V_14 , V_56 , V_57 , & V_52 , V_58 , V_59 ) ;
if ( ! V_48 )
return - V_38 ;
if ( F_30 ( V_21 , V_14 ) < 0 )
goto V_55;
F_26 ( V_14 , V_48 ) ;
return 0 ;
V_55:
F_28 ( V_14 , V_48 ) ;
return - V_60 ;
}
static int F_34 ( struct V_61 * V_62 )
{
struct V_17 * V_17 = F_35 ( V_62 -> V_14 -> V_63 ) ;
struct V_18 * V_19 ;
struct V_64 * V_65 ;
V_19 = F_4 ( V_17 ) ;
V_65 = (struct V_64 * ) V_62 -> args [ 0 ] ;
if ( ! V_65 ) {
V_65 = F_36 ( sizeof( * V_65 ) , V_37 ) ;
if ( ! V_65 )
return - V_38 ;
V_62 -> args [ 0 ] = ( long ) V_65 ;
}
F_37 ( & V_19 -> V_66 , V_65 ) ;
return 0 ;
}
static int F_38 ( struct V_61 * V_62 )
{
struct V_64 * V_65 = (struct V_64 * ) V_62 -> args [ 0 ] ;
F_39 ( V_65 ) ;
F_13 ( V_65 ) ;
return 0 ;
}
static int F_40 ( struct V_13 * V_14 , struct V_61 * V_62 )
{
struct V_64 * V_65 = (struct V_64 * ) V_62 -> args [ 0 ] ;
struct V_20 * V_21 ;
int V_67 ;
V_67 = F_41 ( V_65 ) ;
if ( V_67 && V_67 != - V_68 )
goto V_69;
for (; ; ) {
V_21 = F_42 ( V_65 ) ;
if ( F_43 ( V_21 ) ) {
if ( F_44 ( V_21 ) == - V_68 )
continue;
V_67 = F_44 ( V_21 ) ;
goto V_69;
} else if ( ! V_21 ) {
break;
}
V_67 = F_33 ( V_21 ,
F_45 ( V_62 -> V_14 ) . V_56 ,
V_62 -> V_70 -> V_71 ,
V_72 ,
V_14 , V_73 ) ;
if ( V_67 )
goto V_69;
}
V_67 = V_14 -> V_3 ;
V_69:
F_46 ( V_65 ) ;
return V_67 ;
}
static int F_34 ( struct V_61 * V_62 )
{
return 0 ;
}
static int F_38 ( struct V_61 * V_62 )
{
return 0 ;
}
static int F_40 ( struct V_13 * V_14 , struct V_61 * V_62 )
{
return - V_40 ;
}
static int T_3 F_47 ( struct V_17 * V_17 )
{
struct V_18 * V_19 ;
V_19 = F_11 ( sizeof( * V_19 ) , V_37 ) ;
if ( ! V_19 )
return - V_38 ;
F_48 ( & V_19 -> V_33 ) ;
V_19 -> V_46 = F_11 ( sizeof( * V_19 -> V_46 ) , V_37 ) ;
if ( ! V_19 -> V_46 ) {
F_13 ( V_19 ) ;
return - V_38 ;
}
V_17 -> V_74 . V_75 = V_19 ;
#ifdef F_49
F_50 ( V_17 ) ;
#endif
return 0 ;
}
static void T_4 F_51 ( struct V_17 * V_17 )
{
struct V_18 * V_19 = F_4 ( V_17 ) ;
#ifdef F_49
F_52 ( V_17 ) ;
#endif
F_13 ( V_19 -> V_46 ) ;
F_13 ( V_19 ) ;
}
int T_5 F_53 ( void )
{
int V_24 = - V_38 ;
V_24 = F_54 ( & V_52 ) ;
if ( V_24 )
goto V_76;
V_24 = F_55 ( & V_77 ) ;
if ( V_24 )
goto V_78;
#ifdef F_56
V_24 = F_57 () ;
if ( V_24 )
goto V_79;
#endif
#ifdef F_49
V_24 = F_58 () ;
if ( V_24 )
goto V_80;
#endif
F_59 ( L_1 ) ;
V_76:
return V_24 ;
#ifdef F_49
V_80:
#ifdef F_56
F_60 () ;
#endif
#endif
#ifdef F_56
V_79:
F_61 ( & V_77 ) ;
#endif
V_78:
F_62 ( & V_52 ) ;
goto V_76;
}
void F_63 ( void )
{
#ifdef F_49
F_64 () ;
#endif
#ifdef F_56
F_60 () ;
#endif
F_61 ( & V_77 ) ;
F_62 ( & V_52 ) ;
}
