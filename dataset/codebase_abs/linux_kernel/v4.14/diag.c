static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) -> V_6 ;
if ( ! V_6 )
return 0 ;
return F_3 ( V_4 , V_7 , V_6 -> V_8 - sizeof( short ) ,
V_6 -> V_9 -> V_10 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_11 = F_2 ( V_2 ) -> V_12 . V_11 ;
if ( V_11 ) {
struct V_13 V_14 = {
. V_15 = F_5 ( V_11 ) -> V_16 ,
. V_17 = V_11 -> V_18 -> V_19 ,
} ;
return F_3 ( V_4 , V_20 , sizeof( V_14 ) , & V_14 ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_21 ;
int V_22 ;
V_21 = F_7 ( V_2 ) ;
if ( V_21 ) {
F_8 ( V_21 ) ;
V_22 = F_9 ( V_21 ) ;
F_10 ( V_21 ) ;
F_11 ( V_21 ) ;
return F_12 ( V_4 , V_23 , V_22 ) ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_24 ;
struct V_25 * V_26 ;
T_1 * V_27 ;
int V_28 ;
if ( V_2 -> V_29 == V_30 ) {
F_14 ( & V_2 -> V_31 . V_32 ) ;
V_26 = F_15 ( V_4 , V_33 ,
V_2 -> V_31 . V_34 * sizeof( T_1 ) ) ;
if ( ! V_26 )
goto V_35;
V_27 = F_16 ( V_26 ) ;
V_28 = 0 ;
F_17 (&sk->sk_receive_queue, skb) {
struct V_1 * V_36 , * V_21 ;
V_36 = V_24 -> V_2 ;
F_18 ( V_36 ) ;
V_21 = F_2 ( V_36 ) -> V_21 ;
V_27 [ V_28 ++ ] = ( V_21 ? F_9 ( V_21 ) : 0 ) ;
F_10 ( V_36 ) ;
}
F_19 ( & V_2 -> V_31 . V_32 ) ;
}
return 0 ;
V_35:
F_19 ( & V_2 -> V_31 . V_32 ) ;
return - V_37 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_38 V_39 ;
if ( V_2 -> V_29 == V_30 ) {
V_39 . V_40 = V_2 -> V_31 . V_34 ;
V_39 . V_41 = V_2 -> V_42 ;
} else {
V_39 . V_40 = ( T_1 ) F_21 ( V_2 ) ;
V_39 . V_41 = ( T_1 ) F_22 ( V_2 ) ;
}
return F_3 ( V_4 , V_43 , sizeof( V_39 ) , & V_39 ) ;
}
static int F_23 ( struct V_1 * V_2 , struct V_3 * V_24 , struct V_44 * V_36 ,
T_1 V_45 , T_1 V_46 , T_1 V_47 , int V_48 )
{
struct V_49 * V_50 ;
struct V_51 * V_52 ;
V_50 = F_24 ( V_24 , V_45 , V_46 , V_53 , sizeof( * V_52 ) ,
V_47 ) ;
if ( ! V_50 )
return - V_37 ;
V_52 = F_25 ( V_50 ) ;
V_52 -> V_54 = V_55 ;
V_52 -> V_56 = V_2 -> V_57 ;
V_52 -> V_58 = V_2 -> V_29 ;
V_52 -> V_59 = 0 ;
V_52 -> V_60 = V_48 ;
F_26 ( V_2 , V_52 -> V_61 ) ;
if ( ( V_36 -> V_62 & V_63 ) &&
F_1 ( V_2 , V_24 ) )
goto V_64;
if ( ( V_36 -> V_62 & V_65 ) &&
F_4 ( V_2 , V_24 ) )
goto V_64;
if ( ( V_36 -> V_62 & V_66 ) &&
F_6 ( V_2 , V_24 ) )
goto V_64;
if ( ( V_36 -> V_62 & V_67 ) &&
F_13 ( V_2 , V_24 ) )
goto V_64;
if ( ( V_36 -> V_62 & V_68 ) &&
F_20 ( V_2 , V_24 ) )
goto V_64;
if ( ( V_36 -> V_62 & V_69 ) &&
F_27 ( V_2 , V_24 , V_70 ) )
goto V_64;
if ( F_28 ( V_24 , V_71 , V_2 -> V_72 ) )
goto V_64;
F_29 ( V_24 , V_50 ) ;
return 0 ;
V_64:
F_30 ( V_24 , V_50 ) ;
return - V_37 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_3 * V_24 , struct V_44 * V_36 ,
T_1 V_45 , T_1 V_46 , T_1 V_47 )
{
int V_48 ;
F_8 ( V_2 ) ;
V_48 = F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
if ( ! V_48 )
return 0 ;
return F_23 ( V_2 , V_24 , V_36 , V_45 , V_46 , V_47 , V_48 ) ;
}
static int F_32 ( struct V_3 * V_24 , struct V_73 * V_74 )
{
struct V_44 * V_36 ;
int V_75 , V_76 , V_77 , V_78 ;
struct V_79 * V_79 = F_33 ( V_24 -> V_2 ) ;
V_36 = F_25 ( V_74 -> V_50 ) ;
V_78 = V_74 -> args [ 0 ] ;
V_75 = V_76 = V_74 -> args [ 1 ] ;
F_14 ( & V_80 ) ;
for ( V_77 = V_78 ;
V_77 < F_34 ( V_81 ) ;
V_76 = 0 , V_77 ++ ) {
struct V_1 * V_2 ;
V_75 = 0 ;
F_35 (sk, &unix_socket_table[slot]) {
if ( ! F_36 ( F_33 ( V_2 ) , V_79 ) )
continue;
if ( V_75 < V_76 )
goto V_82;
if ( ! ( V_36 -> V_83 & ( 1 << V_2 -> V_29 ) ) )
goto V_82;
if ( F_31 ( V_2 , V_24 , V_36 ,
F_37 ( V_74 -> V_24 ) . V_45 ,
V_74 -> V_50 -> V_84 ,
V_85 ) < 0 )
goto V_86;
V_82:
V_75 ++ ;
}
}
V_86:
F_19 ( & V_80 ) ;
V_74 -> args [ 0 ] = V_77 ;
V_74 -> args [ 1 ] = V_75 ;
return V_24 -> V_8 ;
}
static struct V_1 * F_38 ( unsigned int V_22 )
{
int V_28 ;
struct V_1 * V_2 ;
F_14 ( & V_80 ) ;
for ( V_28 = 0 ; V_28 < F_34 ( V_81 ) ; V_28 ++ ) {
F_35 (sk, &unix_socket_table[i])
if ( V_22 == F_9 ( V_2 ) ) {
F_39 ( V_2 ) ;
F_19 ( & V_80 ) ;
return V_2 ;
}
}
F_19 ( & V_80 ) ;
return NULL ;
}
static int F_40 ( struct V_3 * V_87 ,
const struct V_49 * V_50 ,
struct V_44 * V_36 )
{
int V_88 = - V_89 ;
struct V_1 * V_2 ;
struct V_3 * V_52 ;
unsigned int V_90 ;
struct V_79 * V_79 = F_33 ( V_87 -> V_2 ) ;
if ( V_36 -> V_60 == 0 )
goto V_91;
V_2 = F_38 ( V_36 -> V_60 ) ;
V_88 = - V_92 ;
if ( V_2 == NULL )
goto V_91;
if ( ! F_36 ( F_33 ( V_2 ) , V_79 ) )
goto V_93;
V_88 = F_41 ( V_2 , V_36 -> V_61 ) ;
if ( V_88 )
goto V_93;
V_90 = 256 ;
V_94:
V_88 = - V_95 ;
V_52 = F_42 ( sizeof( struct V_51 ) + V_90 , V_96 ) ;
if ( ! V_52 )
goto V_93;
V_88 = F_23 ( V_2 , V_52 , V_36 , F_37 ( V_87 ) . V_45 ,
V_50 -> V_84 , 0 , V_36 -> V_60 ) ;
if ( V_88 < 0 ) {
F_43 ( V_52 ) ;
V_90 += 256 ;
if ( V_90 >= V_97 )
goto V_93;
goto V_94;
}
V_88 = F_44 ( V_79 -> V_98 , V_52 , F_37 ( V_87 ) . V_45 ,
V_99 ) ;
if ( V_88 > 0 )
V_88 = 0 ;
V_93:
if ( V_2 )
F_11 ( V_2 ) ;
V_91:
return V_88 ;
}
static int F_45 ( struct V_3 * V_24 , struct V_49 * V_100 )
{
int V_101 = sizeof( struct V_44 ) ;
struct V_79 * V_79 = F_33 ( V_24 -> V_2 ) ;
if ( F_46 ( V_100 ) < V_101 )
return - V_89 ;
if ( V_100 -> V_102 & V_103 ) {
struct V_104 V_105 = {
. V_106 = F_32 ,
} ;
return F_47 ( V_79 -> V_98 , V_24 , V_100 , & V_105 ) ;
} else
return F_40 ( V_24 , V_100 , F_25 ( V_100 ) ) ;
}
static int T_2 F_48 ( void )
{
return F_49 ( & V_107 ) ;
}
static void T_3 F_50 ( void )
{
F_51 ( & V_107 ) ;
}
