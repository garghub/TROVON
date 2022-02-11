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
. V_15 = V_11 -> V_16 -> V_17 ,
. V_18 = V_11 -> V_19 -> V_20 ,
} ;
return F_3 ( V_4 , V_21 , sizeof( V_14 ) , & V_14 ) ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_22 ;
int V_23 ;
V_22 = F_6 ( V_2 ) ;
if ( V_22 ) {
F_7 ( V_22 ) ;
V_23 = F_8 ( V_22 ) ;
F_9 ( V_22 ) ;
F_10 ( V_22 ) ;
return F_11 ( V_4 , V_24 , V_23 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_25 ;
struct V_26 * V_27 ;
T_1 * V_28 ;
int V_29 ;
if ( V_2 -> V_30 == V_31 ) {
F_13 ( & V_2 -> V_32 . V_33 ) ;
V_27 = F_14 ( V_4 , V_34 ,
V_2 -> V_32 . V_35 * sizeof( T_1 ) ) ;
if ( ! V_27 )
goto V_36;
V_28 = F_15 ( V_27 ) ;
V_29 = 0 ;
F_16 (&sk->sk_receive_queue, skb) {
struct V_1 * V_37 , * V_22 ;
V_37 = V_25 -> V_2 ;
F_17 ( V_37 ) ;
V_22 = F_2 ( V_37 ) -> V_22 ;
V_28 [ V_29 ++ ] = ( V_22 ? F_8 ( V_22 ) : 0 ) ;
F_9 ( V_37 ) ;
}
F_18 ( & V_2 -> V_32 . V_33 ) ;
}
return 0 ;
V_36:
F_18 ( & V_2 -> V_32 . V_33 ) ;
return - V_38 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_39 V_40 ;
if ( V_2 -> V_30 == V_31 ) {
V_40 . V_41 = V_2 -> V_32 . V_35 ;
V_40 . V_42 = V_2 -> V_43 ;
} else {
V_40 . V_41 = ( T_1 ) F_20 ( V_2 ) ;
V_40 . V_42 = ( T_1 ) F_21 ( V_2 ) ;
}
return F_3 ( V_4 , V_44 , sizeof( V_40 ) , & V_40 ) ;
}
static int F_22 ( struct V_1 * V_2 , struct V_3 * V_25 , struct V_45 * V_37 ,
T_1 V_46 , T_1 V_47 , T_1 V_48 , int V_49 )
{
struct V_50 * V_51 ;
struct V_52 * V_53 ;
V_51 = F_23 ( V_25 , V_46 , V_47 , V_54 , sizeof( * V_53 ) ,
V_48 ) ;
if ( ! V_51 )
return - V_38 ;
V_53 = F_24 ( V_51 ) ;
V_53 -> V_55 = V_56 ;
V_53 -> V_57 = V_2 -> V_58 ;
V_53 -> V_59 = V_2 -> V_30 ;
V_53 -> V_60 = 0 ;
V_53 -> V_61 = V_49 ;
F_25 ( V_2 , V_53 -> V_62 ) ;
if ( ( V_37 -> V_63 & V_64 ) &&
F_1 ( V_2 , V_25 ) )
goto V_65;
if ( ( V_37 -> V_63 & V_66 ) &&
F_4 ( V_2 , V_25 ) )
goto V_65;
if ( ( V_37 -> V_63 & V_67 ) &&
F_5 ( V_2 , V_25 ) )
goto V_65;
if ( ( V_37 -> V_63 & V_68 ) &&
F_12 ( V_2 , V_25 ) )
goto V_65;
if ( ( V_37 -> V_63 & V_69 ) &&
F_19 ( V_2 , V_25 ) )
goto V_65;
if ( ( V_37 -> V_63 & V_70 ) &&
F_26 ( V_2 , V_25 , V_71 ) )
goto V_65;
if ( F_27 ( V_25 , V_72 , V_2 -> V_73 ) )
goto V_65;
return F_28 ( V_25 , V_51 ) ;
V_65:
F_29 ( V_25 , V_51 ) ;
return - V_38 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_3 * V_25 , struct V_45 * V_37 ,
T_1 V_46 , T_1 V_47 , T_1 V_48 )
{
int V_49 ;
F_7 ( V_2 ) ;
V_49 = F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
if ( ! V_49 )
return 0 ;
return F_22 ( V_2 , V_25 , V_37 , V_46 , V_47 , V_48 , V_49 ) ;
}
static int F_31 ( struct V_3 * V_25 , struct V_74 * V_75 )
{
struct V_45 * V_37 ;
int V_76 , V_77 , V_78 , V_79 ;
struct V_80 * V_80 = F_32 ( V_25 -> V_2 ) ;
V_37 = F_24 ( V_75 -> V_51 ) ;
V_79 = V_75 -> args [ 0 ] ;
V_76 = V_77 = V_75 -> args [ 1 ] ;
F_13 ( & V_81 ) ;
for ( V_78 = V_79 ;
V_78 < F_33 ( V_82 ) ;
V_77 = 0 , V_78 ++ ) {
struct V_1 * V_2 ;
V_76 = 0 ;
F_34 (sk, &unix_socket_table[slot]) {
if ( ! F_35 ( F_32 ( V_2 ) , V_80 ) )
continue;
if ( V_76 < V_77 )
goto V_83;
if ( ! ( V_37 -> V_84 & ( 1 << V_2 -> V_30 ) ) )
goto V_83;
if ( F_30 ( V_2 , V_25 , V_37 ,
F_36 ( V_75 -> V_25 ) . V_46 ,
V_75 -> V_51 -> V_85 ,
V_86 ) < 0 )
goto V_87;
V_83:
V_76 ++ ;
}
}
V_87:
F_18 ( & V_81 ) ;
V_75 -> args [ 0 ] = V_78 ;
V_75 -> args [ 1 ] = V_76 ;
return V_25 -> V_8 ;
}
static struct V_1 * F_37 ( int V_23 )
{
int V_29 ;
struct V_1 * V_2 ;
F_13 ( & V_81 ) ;
for ( V_29 = 0 ; V_29 < F_33 ( V_82 ) ; V_29 ++ ) {
F_34 (sk, &unix_socket_table[i])
if ( V_23 == F_8 ( V_2 ) ) {
F_38 ( V_2 ) ;
F_18 ( & V_81 ) ;
return V_2 ;
}
}
F_18 ( & V_81 ) ;
return NULL ;
}
static int F_39 ( struct V_3 * V_88 ,
const struct V_50 * V_51 ,
struct V_45 * V_37 )
{
int V_89 = - V_90 ;
struct V_1 * V_2 ;
struct V_3 * V_53 ;
unsigned int V_91 ;
struct V_80 * V_80 = F_32 ( V_88 -> V_2 ) ;
if ( V_37 -> V_61 == 0 )
goto V_92;
V_2 = F_37 ( V_37 -> V_61 ) ;
V_89 = - V_93 ;
if ( V_2 == NULL )
goto V_92;
V_89 = F_40 ( V_2 , V_37 -> V_62 ) ;
if ( V_89 )
goto V_94;
V_91 = 256 ;
V_95:
V_89 = - V_96 ;
V_53 = F_41 ( sizeof( struct V_52 ) + V_91 , V_97 ) ;
if ( ! V_53 )
goto V_94;
V_89 = F_22 ( V_2 , V_53 , V_37 , F_36 ( V_88 ) . V_46 ,
V_51 -> V_85 , 0 , V_37 -> V_61 ) ;
if ( V_89 < 0 ) {
F_42 ( V_53 ) ;
V_91 += 256 ;
if ( V_91 >= V_98 )
goto V_94;
goto V_95;
}
V_89 = F_43 ( V_80 -> V_99 , V_53 , F_36 ( V_88 ) . V_46 ,
V_100 ) ;
if ( V_89 > 0 )
V_89 = 0 ;
V_94:
if ( V_2 )
F_10 ( V_2 ) ;
V_92:
return V_89 ;
}
static int F_44 ( struct V_3 * V_25 , struct V_50 * V_101 )
{
int V_102 = sizeof( struct V_45 ) ;
struct V_80 * V_80 = F_32 ( V_25 -> V_2 ) ;
if ( F_45 ( V_101 ) < V_102 )
return - V_90 ;
if ( V_101 -> V_103 & V_104 ) {
struct V_105 V_106 = {
. V_107 = F_31 ,
} ;
return F_46 ( V_80 -> V_99 , V_25 , V_101 , & V_106 ) ;
} else
return F_39 ( V_25 , V_101 , F_24 ( V_101 ) ) ;
}
static int T_2 F_47 ( void )
{
return F_48 ( & V_108 ) ;
}
static void T_3 F_49 ( void )
{
F_50 ( & V_108 ) ;
}
