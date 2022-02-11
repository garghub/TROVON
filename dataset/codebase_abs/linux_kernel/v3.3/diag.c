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
struct V_14 * V_14 = F_2 ( V_2 ) -> V_14 ;
struct V_15 * V_16 ;
if ( V_14 ) {
V_16 = F_3 ( V_4 , V_17 , sizeof( * V_16 ) ) ;
V_16 -> V_18 = V_14 -> V_19 -> V_20 ;
V_16 -> V_21 = V_14 -> V_22 -> V_23 ;
}
return 0 ;
V_12:
return - V_13 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_24 ;
int V_25 ;
V_24 = F_6 ( V_2 ) ;
if ( V_24 ) {
F_7 ( V_24 ) ;
V_25 = F_8 ( V_24 ) ;
F_9 ( V_24 ) ;
F_10 ( V_24 ) ;
F_11 ( V_4 , V_26 , V_25 ) ;
}
return 0 ;
V_12:
return - V_13 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_27 ;
T_1 * V_28 ;
int V_29 ;
if ( V_2 -> V_30 == V_31 ) {
F_13 ( & V_2 -> V_32 . V_33 ) ;
V_28 = F_3 ( V_4 , V_34 ,
V_2 -> V_32 . V_35 * sizeof( T_1 ) ) ;
V_29 = 0 ;
F_14 (&sk->sk_receive_queue, skb) {
struct V_1 * V_36 , * V_24 ;
V_36 = V_27 -> V_2 ;
F_15 ( V_36 ) ;
V_24 = F_2 ( V_36 ) -> V_24 ;
V_28 [ V_29 ++ ] = ( V_24 ? F_8 ( V_24 ) : 0 ) ;
F_9 ( V_36 ) ;
}
F_16 ( & V_2 -> V_32 . V_33 ) ;
}
return 0 ;
V_12:
F_16 ( & V_2 -> V_32 . V_33 ) ;
return - V_13 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_37 * V_38 ;
V_38 = F_3 ( V_4 , V_39 , sizeof( * V_38 ) ) ;
if ( V_2 -> V_30 == V_31 ) {
V_38 -> V_40 = V_2 -> V_32 . V_35 ;
V_38 -> V_41 = V_2 -> V_42 ;
} else {
V_38 -> V_40 = ( V_43 ) F_18 ( V_2 ) ;
V_38 -> V_41 = ( V_43 ) F_19 ( V_2 ) ;
}
return 0 ;
V_12:
return - V_13 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_3 * V_27 , struct V_44 * V_36 ,
T_1 V_45 , T_1 V_46 , T_1 V_47 , int V_48 )
{
unsigned char * V_49 = F_21 ( V_27 ) ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
V_51 = F_22 ( V_27 , V_45 , V_46 , V_54 , sizeof( * V_53 ) ) ;
V_51 -> V_55 = V_47 ;
V_53 = F_23 ( V_51 ) ;
V_53 -> V_56 = V_57 ;
V_53 -> V_58 = V_2 -> V_59 ;
V_53 -> V_60 = V_2 -> V_30 ;
V_53 -> V_61 = V_48 ;
F_24 ( V_2 , V_53 -> V_62 ) ;
if ( ( V_36 -> V_63 & V_64 ) &&
F_1 ( V_2 , V_27 ) )
goto V_65;
if ( ( V_36 -> V_63 & V_66 ) &&
F_4 ( V_2 , V_27 ) )
goto V_65;
if ( ( V_36 -> V_63 & V_67 ) &&
F_5 ( V_2 , V_27 ) )
goto V_65;
if ( ( V_36 -> V_63 & V_68 ) &&
F_12 ( V_2 , V_27 ) )
goto V_65;
if ( ( V_36 -> V_63 & V_69 ) &&
F_17 ( V_2 , V_27 ) )
goto V_65;
if ( ( V_36 -> V_63 & V_70 ) &&
F_25 ( V_2 , V_27 , V_71 ) )
goto V_65;
V_51 -> V_72 = F_21 ( V_27 ) - V_49 ;
return V_27 -> V_9 ;
V_65:
F_26 ( V_27 , V_49 ) ;
return - V_13 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_3 * V_27 , struct V_44 * V_36 ,
T_1 V_45 , T_1 V_46 , T_1 V_47 )
{
int V_48 ;
F_7 ( V_2 ) ;
V_48 = F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
if ( ! V_48 )
return 0 ;
return F_20 ( V_2 , V_27 , V_36 , V_45 , V_46 , V_47 , V_48 ) ;
}
static int F_28 ( struct V_3 * V_27 , struct V_73 * V_74 )
{
struct V_44 * V_36 ;
int V_75 , V_76 , V_77 , V_78 ;
V_36 = F_23 ( V_74 -> V_51 ) ;
V_78 = V_74 -> args [ 0 ] ;
V_75 = V_76 = V_74 -> args [ 1 ] ;
F_13 ( & V_79 ) ;
for ( V_77 = V_78 ; V_77 <= V_80 ; V_76 = 0 , V_77 ++ ) {
struct V_1 * V_2 ;
struct V_81 * V_82 ;
V_75 = 0 ;
F_29 (sk, node, &unix_socket_table[slot]) {
if ( V_75 < V_76 )
goto V_83;
if ( ! ( V_36 -> V_84 & ( 1 << V_2 -> V_30 ) ) )
goto V_83;
if ( F_27 ( V_2 , V_27 , V_36 ,
F_30 ( V_74 -> V_27 ) . V_45 ,
V_74 -> V_51 -> V_85 ,
V_86 ) < 0 )
goto V_87;
V_83:
V_75 ++ ;
}
}
V_87:
F_16 ( & V_79 ) ;
V_74 -> args [ 0 ] = V_77 ;
V_74 -> args [ 1 ] = V_75 ;
return V_27 -> V_9 ;
}
static struct V_1 * F_31 ( int V_25 )
{
int V_29 ;
struct V_1 * V_2 ;
F_13 ( & V_79 ) ;
for ( V_29 = 0 ; V_29 <= V_80 ; V_29 ++ ) {
struct V_81 * V_82 ;
F_29 (sk, node, &unix_socket_table[i])
if ( V_25 == F_8 ( V_2 ) ) {
F_32 ( V_2 ) ;
F_16 ( & V_79 ) ;
return V_2 ;
}
}
F_16 ( & V_79 ) ;
return NULL ;
}
static int F_33 ( struct V_3 * V_88 ,
const struct V_50 * V_51 ,
struct V_44 * V_36 )
{
int V_89 = - V_90 ;
struct V_1 * V_2 ;
struct V_3 * V_53 ;
unsigned int V_91 ;
if ( V_36 -> V_61 == 0 )
goto V_92;
V_2 = F_31 ( V_36 -> V_61 ) ;
V_89 = - V_93 ;
if ( V_2 == NULL )
goto V_92;
V_89 = F_34 ( V_2 , V_36 -> V_62 ) ;
if ( V_89 )
goto V_94;
V_91 = 256 ;
V_95:
V_89 = - V_96 ;
V_53 = F_35 ( F_36 ( ( sizeof( struct V_52 ) + V_91 ) ) ,
V_97 ) ;
if ( ! V_53 )
goto V_94;
V_89 = F_20 ( V_2 , V_53 , V_36 , F_30 ( V_88 ) . V_45 ,
V_51 -> V_85 , 0 , V_36 -> V_61 ) ;
if ( V_89 < 0 ) {
F_37 ( V_53 ) ;
V_91 += 256 ;
if ( V_91 >= V_98 )
goto V_94;
goto V_95;
}
V_89 = F_38 ( V_99 , V_53 , F_30 ( V_88 ) . V_45 ,
V_100 ) ;
if ( V_89 > 0 )
V_89 = 0 ;
V_94:
if ( V_2 )
F_10 ( V_2 ) ;
V_92:
return V_89 ;
}
static int F_39 ( struct V_3 * V_27 , struct V_50 * V_101 )
{
int V_102 = sizeof( struct V_44 ) ;
if ( V_72 ( V_101 ) < V_102 )
return - V_90 ;
if ( V_101 -> V_55 & V_103 )
return F_40 ( V_99 , V_27 , V_101 ,
F_28 , NULL , 0 ) ;
else
return F_33 ( V_27 , V_101 , (struct V_44 * ) F_23 ( V_101 ) ) ;
}
static int T_2 F_41 ( void )
{
return F_42 ( & V_104 ) ;
}
static void T_3 F_43 ( void )
{
F_44 ( & V_104 ) ;
}
