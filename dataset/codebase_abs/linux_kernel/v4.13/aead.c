static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
unsigned long V_5 = F_2 ( V_2 ) ;
int V_6 ;
T_1 * V_7 , * V_8 ;
unsigned long V_9 ;
V_9 = V_4 + V_5 ;
V_7 = F_3 ( V_9 , V_10 ) ;
if ( ! V_7 )
return - V_11 ;
V_8 = ( T_1 * ) F_4 ( ( unsigned long ) V_7 , V_5 + 1 ) ;
memcpy ( V_8 , V_3 , V_4 ) ;
V_6 = F_5 ( V_2 ) -> F_6 ( V_2 , V_8 , V_4 ) ;
memset ( V_8 , 0 , V_4 ) ;
F_7 ( V_7 ) ;
return V_6 ;
}
int F_8 ( struct V_1 * V_2 ,
const T_1 * V_3 , unsigned int V_4 )
{
unsigned long V_5 = F_2 ( V_2 ) ;
if ( ( unsigned long ) V_3 & V_5 )
return F_1 ( V_2 , V_3 , V_4 ) ;
return F_5 ( V_2 ) -> F_6 ( V_2 , V_3 , V_4 ) ;
}
int F_9 ( struct V_1 * V_2 , unsigned int V_12 )
{
int V_13 ;
if ( V_12 > F_10 ( V_2 ) )
return - V_14 ;
if ( F_5 ( V_2 ) -> V_15 ) {
V_13 = F_5 ( V_2 ) -> V_15 ( V_2 , V_12 ) ;
if ( V_13 )
return V_13 ;
}
V_2 -> V_12 = V_12 ;
return 0 ;
}
static void F_11 ( struct V_16 * V_2 )
{
struct V_1 * V_17 = F_12 ( V_2 ) ;
struct V_18 * V_19 = F_5 ( V_17 ) ;
V_19 -> exit ( V_17 ) ;
}
static int F_13 ( struct V_16 * V_2 )
{
struct V_1 * V_17 = F_12 ( V_2 ) ;
struct V_18 * V_19 = F_5 ( V_17 ) ;
V_17 -> V_12 = V_19 -> V_20 ;
if ( V_19 -> exit )
V_17 -> V_21 . exit = F_11 ;
if ( V_19 -> V_22 )
return V_19 -> V_22 ( V_17 ) ;
return 0 ;
}
static int F_14 ( struct V_23 * V_24 , struct V_25 * V_19 )
{
struct V_26 V_27 ;
struct V_18 * V_17 = F_15 ( V_19 , struct V_18 , V_21 ) ;
strncpy ( V_27 . type , L_1 , sizeof( V_27 . type ) ) ;
strncpy ( V_27 . V_28 , L_2 , sizeof( V_27 . V_28 ) ) ;
V_27 . V_29 = V_19 -> V_30 ;
V_27 . V_20 = V_17 -> V_20 ;
V_27 . V_31 = V_17 -> V_31 ;
if ( F_16 ( V_24 , V_32 ,
sizeof( struct V_26 ) , & V_27 ) )
goto V_33;
return 0 ;
V_33:
return - V_34 ;
}
static int F_14 ( struct V_23 * V_24 , struct V_25 * V_19 )
{
return - V_35 ;
}
static void F_17 ( struct V_36 * V_37 , struct V_25 * V_19 )
{
struct V_18 * V_17 = F_15 ( V_19 , struct V_18 , V_21 ) ;
F_18 ( V_37 , L_3 ) ;
F_18 ( V_37 , L_4 , V_19 -> V_38 & V_39 ?
L_5 : L_6 ) ;
F_18 ( V_37 , L_7 , V_19 -> V_30 ) ;
F_18 ( V_37 , L_8 , V_17 -> V_31 ) ;
F_18 ( V_37 , L_9 , V_17 -> V_20 ) ;
F_18 ( V_37 , L_10 ) ;
}
static void F_19 ( struct V_40 * V_41 )
{
struct V_42 * V_17 = V_42 ( V_41 ) ;
if ( ! V_17 -> free ) {
V_41 -> V_43 -> free ( V_41 ) ;
return;
}
V_17 -> free ( V_17 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
const T_1 * V_3 , unsigned int V_4 )
{
struct V_44 * V_45 = F_21 ( V_2 ) ;
return F_8 ( V_45 -> V_46 , V_3 , V_4 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned int V_12 )
{
struct V_44 * V_45 = F_21 ( V_2 ) ;
return F_9 ( V_45 -> V_46 , V_12 ) ;
}
struct V_42 * F_23 ( struct V_47 * V_43 ,
struct V_48 * * V_49 , T_2 type , T_2 V_50 )
{
const char * V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_42 * V_41 ;
struct V_18 * V_19 ;
unsigned int V_31 ;
unsigned int V_20 ;
int V_13 ;
V_55 = F_24 ( V_49 ) ;
if ( F_25 ( V_55 ) )
return F_26 ( V_55 ) ;
if ( ( V_55 -> type ^ V_56 ) & V_55 -> V_50 )
return F_27 ( - V_14 ) ;
V_51 = F_28 ( V_49 [ 1 ] ) ;
if ( F_25 ( V_51 ) )
return F_26 ( V_51 ) ;
V_41 = F_29 ( sizeof( * V_41 ) + sizeof( * V_53 ) , V_57 ) ;
if ( ! V_41 )
return F_27 ( - V_11 ) ;
V_53 = F_30 ( V_41 ) ;
V_50 |= F_31 ( V_55 -> type , V_55 -> V_50 ) ;
F_32 ( V_53 , F_33 ( V_41 ) ) ;
V_13 = F_34 ( V_53 , V_51 , type , V_50 ) ;
if ( V_13 )
goto V_58;
V_19 = F_35 ( V_53 ) ;
V_31 = F_36 ( V_19 ) ;
V_20 = F_37 ( V_19 ) ;
V_13 = - V_14 ;
if ( V_31 < sizeof( V_59 ) )
goto V_60;
V_13 = - V_61 ;
if ( snprintf ( V_41 -> V_19 . V_21 . V_62 , V_63 ,
L_11 , V_43 -> V_51 , V_19 -> V_21 . V_62 ) >=
V_63 )
goto V_60;
if ( snprintf ( V_41 -> V_19 . V_21 . V_64 , V_63 ,
L_11 , V_43 -> V_51 , V_19 -> V_21 . V_64 ) >=
V_63 )
goto V_60;
V_41 -> V_19 . V_21 . V_38 = V_19 -> V_21 . V_38 & V_39 ;
V_41 -> V_19 . V_21 . V_65 = V_19 -> V_21 . V_65 ;
V_41 -> V_19 . V_21 . V_30 = V_19 -> V_21 . V_30 ;
V_41 -> V_19 . V_21 . V_66 = V_19 -> V_21 . V_66 ;
V_41 -> V_19 . V_21 . V_67 = sizeof( struct V_44 ) ;
V_41 -> V_19 . F_6 = F_20 ;
V_41 -> V_19 . V_15 = F_22 ;
V_41 -> V_19 . V_31 = V_31 ;
V_41 -> V_19 . V_20 = V_20 ;
V_68:
return V_41 ;
V_60:
F_38 ( V_53 ) ;
V_58:
F_7 ( V_41 ) ;
V_41 = F_27 ( V_13 ) ;
goto V_68;
}
void F_39 ( struct V_42 * V_41 )
{
F_38 ( F_30 ( V_41 ) ) ;
F_7 ( V_41 ) ;
}
int F_40 ( struct V_1 * V_17 )
{
struct V_44 * V_45 = F_21 ( V_17 ) ;
struct V_42 * V_41 = F_41 ( V_17 ) ;
struct V_1 * V_46 ;
int V_13 ;
F_42 ( & V_45 -> V_69 ) ;
V_13 = F_43 () ;
if ( V_13 )
goto V_68;
V_13 = F_44 ( V_70 , V_45 -> V_71 ,
F_45 ( V_17 ) ) ;
F_46 () ;
if ( V_13 )
goto V_68;
V_45 -> V_72 = F_47 () ;
V_13 = F_48 ( V_45 -> V_72 ) ;
if ( F_25 ( V_45 -> V_72 ) )
goto V_68;
V_46 = F_49 ( F_30 ( V_41 ) ) ;
V_13 = F_48 ( V_46 ) ;
if ( F_25 ( V_46 ) )
goto V_73;
V_45 -> V_46 = V_46 ;
F_50 ( V_17 , F_51 ( V_46 ) +
sizeof( struct V_74 ) ) ;
V_13 = 0 ;
V_68:
return V_13 ;
V_73:
F_52 () ;
goto V_68;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = F_21 ( V_2 ) ;
F_54 ( V_45 -> V_46 ) ;
F_52 () ;
}
int F_34 ( struct V_52 * V_53 , const char * V_51 ,
T_2 type , T_2 V_50 )
{
V_53 -> V_21 . V_75 = & V_76 ;
return F_55 ( & V_53 -> V_21 , V_51 , type , V_50 ) ;
}
struct V_1 * F_56 ( const char * V_77 , T_2 type , T_2 V_50 )
{
return F_57 ( V_77 , & V_76 , type , V_50 ) ;
}
static int F_58 ( struct V_18 * V_19 )
{
struct V_25 * V_21 = & V_19 -> V_21 ;
if ( F_59 ( V_19 -> V_20 , V_19 -> V_31 , V_19 -> V_78 ) >
V_79 / 8 )
return - V_14 ;
if ( ! V_19 -> V_78 )
V_19 -> V_78 = V_21 -> V_30 ;
V_21 -> V_80 = & V_76 ;
V_21 -> V_38 &= ~ V_81 ;
V_21 -> V_38 |= V_56 ;
return 0 ;
}
int F_60 ( struct V_18 * V_19 )
{
struct V_25 * V_21 = & V_19 -> V_21 ;
int V_13 ;
V_13 = F_58 ( V_19 ) ;
if ( V_13 )
return V_13 ;
return F_61 ( V_21 ) ;
}
void F_62 ( struct V_18 * V_19 )
{
F_63 ( & V_19 -> V_21 ) ;
}
int F_64 ( struct V_18 * V_82 , int V_83 )
{
int V_84 , V_6 ;
for ( V_84 = 0 ; V_84 < V_83 ; V_84 ++ ) {
V_6 = F_60 ( & V_82 [ V_84 ] ) ;
if ( V_6 )
goto V_13;
}
return 0 ;
V_13:
for ( -- V_84 ; V_84 >= 0 ; -- V_84 )
F_62 ( & V_82 [ V_84 ] ) ;
return V_6 ;
}
void F_65 ( struct V_18 * V_82 , int V_83 )
{
int V_84 ;
for ( V_84 = V_83 - 1 ; V_84 >= 0 ; -- V_84 )
F_62 ( & V_82 [ V_84 ] ) ;
}
int F_66 ( struct V_47 * V_43 ,
struct V_42 * V_41 )
{
int V_13 ;
V_13 = F_58 ( & V_41 -> V_19 ) ;
if ( V_13 )
return V_13 ;
return F_67 ( V_43 , F_33 ( V_41 ) ) ;
}
