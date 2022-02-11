static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) -> V_6 ;
char * V_7 ;
if ( V_6 ) {
V_7 = F_3 ( V_4 , V_8 , V_6 -> V_9 - sizeof( short ) ) ;
memcpy ( V_7 , V_6 -> V_10 -> V_11 , V_6 -> V_9 - sizeof( short ) ) ;
}
return 0 ;
V_12:
return - V_13 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_14 * V_14 = F_2 ( V_2 ) -> V_15 . V_14 ;
struct V_16 * V_17 ;
if ( V_14 ) {
V_17 = F_3 ( V_4 , V_18 , sizeof( * V_17 ) ) ;
V_17 -> V_19 = V_14 -> V_20 -> V_21 ;
V_17 -> V_22 = V_14 -> V_23 -> V_24 ;
}
return 0 ;
V_12:
return - V_13 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_25 ;
int V_26 ;
V_25 = F_6 ( V_2 ) ;
if ( V_25 ) {
F_7 ( V_25 ) ;
V_26 = F_8 ( V_25 ) ;
F_9 ( V_25 ) ;
F_10 ( V_25 ) ;
F_11 ( V_4 , V_27 , V_26 ) ;
}
return 0 ;
V_12:
return - V_13 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_28 ;
T_1 * V_29 ;
int V_30 ;
if ( V_2 -> V_31 == V_32 ) {
F_13 ( & V_2 -> V_33 . V_34 ) ;
V_29 = F_3 ( V_4 , V_35 ,
V_2 -> V_33 . V_36 * sizeof( T_1 ) ) ;
V_30 = 0 ;
F_14 (&sk->sk_receive_queue, skb) {
struct V_1 * V_37 , * V_25 ;
V_37 = V_28 -> V_2 ;
F_15 ( V_37 ) ;
V_25 = F_2 ( V_37 ) -> V_25 ;
V_29 [ V_30 ++ ] = ( V_25 ? F_8 ( V_25 ) : 0 ) ;
F_9 ( V_37 ) ;
}
F_16 ( & V_2 -> V_33 . V_34 ) ;
}
return 0 ;
V_12:
F_16 ( & V_2 -> V_33 . V_34 ) ;
return - V_13 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_38 * V_39 ;
V_39 = F_3 ( V_4 , V_40 , sizeof( * V_39 ) ) ;
if ( V_2 -> V_31 == V_32 ) {
V_39 -> V_41 = V_2 -> V_33 . V_36 ;
V_39 -> V_42 = V_2 -> V_43 ;
} else {
V_39 -> V_41 = ( V_44 ) F_18 ( V_2 ) ;
V_39 -> V_42 = ( V_44 ) F_19 ( V_2 ) ;
}
return 0 ;
V_12:
return - V_13 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_3 * V_28 , struct V_45 * V_37 ,
T_1 V_46 , T_1 V_47 , T_1 V_48 , int V_49 )
{
unsigned char * V_50 = F_21 ( V_28 ) ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
V_52 = F_22 ( V_28 , V_46 , V_47 , V_55 , sizeof( * V_54 ) ) ;
V_52 -> V_56 = V_48 ;
V_54 = F_23 ( V_52 ) ;
V_54 -> V_57 = V_58 ;
V_54 -> V_59 = V_2 -> V_60 ;
V_54 -> V_61 = V_2 -> V_31 ;
V_54 -> V_62 = V_49 ;
F_24 ( V_2 , V_54 -> V_63 ) ;
if ( ( V_37 -> V_64 & V_65 ) &&
F_1 ( V_2 , V_28 ) )
goto V_66;
if ( ( V_37 -> V_64 & V_67 ) &&
F_4 ( V_2 , V_28 ) )
goto V_66;
if ( ( V_37 -> V_64 & V_68 ) &&
F_5 ( V_2 , V_28 ) )
goto V_66;
if ( ( V_37 -> V_64 & V_69 ) &&
F_12 ( V_2 , V_28 ) )
goto V_66;
if ( ( V_37 -> V_64 & V_70 ) &&
F_17 ( V_2 , V_28 ) )
goto V_66;
if ( ( V_37 -> V_64 & V_71 ) &&
F_25 ( V_2 , V_28 , V_72 ) )
goto V_66;
V_52 -> V_73 = F_21 ( V_28 ) - V_50 ;
return V_28 -> V_9 ;
V_66:
F_26 ( V_28 , V_50 ) ;
return - V_13 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_3 * V_28 , struct V_45 * V_37 ,
T_1 V_46 , T_1 V_47 , T_1 V_48 )
{
int V_49 ;
F_7 ( V_2 ) ;
V_49 = F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
if ( ! V_49 )
return 0 ;
return F_20 ( V_2 , V_28 , V_37 , V_46 , V_47 , V_48 , V_49 ) ;
}
static int F_28 ( struct V_3 * V_28 , struct V_74 * V_75 )
{
struct V_45 * V_37 ;
int V_76 , V_77 , V_78 , V_79 ;
V_37 = F_23 ( V_75 -> V_52 ) ;
V_79 = V_75 -> args [ 0 ] ;
V_76 = V_77 = V_75 -> args [ 1 ] ;
F_13 ( & V_80 ) ;
for ( V_78 = V_79 ; V_78 <= V_81 ; V_77 = 0 , V_78 ++ ) {
struct V_1 * V_2 ;
struct V_82 * V_83 ;
V_76 = 0 ;
F_29 (sk, node, &unix_socket_table[slot]) {
if ( V_76 < V_77 )
goto V_84;
if ( ! ( V_37 -> V_85 & ( 1 << V_2 -> V_31 ) ) )
goto V_84;
if ( F_27 ( V_2 , V_28 , V_37 ,
F_30 ( V_75 -> V_28 ) . V_46 ,
V_75 -> V_52 -> V_86 ,
V_87 ) < 0 )
goto V_88;
V_84:
V_76 ++ ;
}
}
V_88:
F_16 ( & V_80 ) ;
V_75 -> args [ 0 ] = V_78 ;
V_75 -> args [ 1 ] = V_76 ;
return V_28 -> V_9 ;
}
static struct V_1 * F_31 ( int V_26 )
{
int V_30 ;
struct V_1 * V_2 ;
F_13 ( & V_80 ) ;
for ( V_30 = 0 ; V_30 <= V_81 ; V_30 ++ ) {
struct V_82 * V_83 ;
F_29 (sk, node, &unix_socket_table[i])
if ( V_26 == F_8 ( V_2 ) ) {
F_32 ( V_2 ) ;
F_16 ( & V_80 ) ;
return V_2 ;
}
}
F_16 ( & V_80 ) ;
return NULL ;
}
static int F_33 ( struct V_3 * V_89 ,
const struct V_51 * V_52 ,
struct V_45 * V_37 )
{
int V_90 = - V_91 ;
struct V_1 * V_2 ;
struct V_3 * V_54 ;
unsigned int V_92 ;
if ( V_37 -> V_62 == 0 )
goto V_93;
V_2 = F_31 ( V_37 -> V_62 ) ;
V_90 = - V_94 ;
if ( V_2 == NULL )
goto V_93;
V_90 = F_34 ( V_2 , V_37 -> V_63 ) ;
if ( V_90 )
goto V_95;
V_92 = 256 ;
V_96:
V_90 = - V_97 ;
V_54 = F_35 ( F_36 ( ( sizeof( struct V_53 ) + V_92 ) ) ,
V_98 ) ;
if ( ! V_54 )
goto V_95;
V_90 = F_20 ( V_2 , V_54 , V_37 , F_30 ( V_89 ) . V_46 ,
V_52 -> V_86 , 0 , V_37 -> V_62 ) ;
if ( V_90 < 0 ) {
F_37 ( V_54 ) ;
V_92 += 256 ;
if ( V_92 >= V_99 )
goto V_95;
goto V_96;
}
V_90 = F_38 ( V_100 , V_54 , F_30 ( V_89 ) . V_46 ,
V_101 ) ;
if ( V_90 > 0 )
V_90 = 0 ;
V_95:
if ( V_2 )
F_10 ( V_2 ) ;
V_93:
return V_90 ;
}
static int F_39 ( struct V_3 * V_28 , struct V_51 * V_102 )
{
int V_103 = sizeof( struct V_45 ) ;
if ( V_73 ( V_102 ) < V_103 )
return - V_91 ;
if ( V_102 -> V_56 & V_104 ) {
struct V_105 V_106 = {
. V_107 = F_28 ,
} ;
return F_40 ( V_100 , V_28 , V_102 , & V_106 ) ;
} else
return F_33 ( V_28 , V_102 , (struct V_45 * ) F_23 ( V_102 ) ) ;
}
static int T_2 F_41 ( void )
{
return F_42 ( & V_108 ) ;
}
static void T_3 F_43 ( void )
{
F_44 ( & V_108 ) ;
}
