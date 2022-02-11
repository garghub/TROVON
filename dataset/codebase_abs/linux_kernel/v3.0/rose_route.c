static int T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_5 , * V_6 , * V_7 ;
struct V_8 * V_8 ;
int V_9 , V_10 = 0 ;
F_2 ( & V_11 ) ;
F_2 ( & V_12 ) ;
V_5 = V_13 ;
while ( V_5 != NULL ) {
if ( ( V_5 -> V_14 == V_2 -> V_14 ) &&
( F_3 ( & V_2 -> V_15 , & V_5 -> V_15 ,
V_2 -> V_14 ) == 0 ) )
break;
V_5 = V_5 -> V_16 ;
}
if ( V_5 != NULL && V_5 -> V_17 ) {
V_10 = - V_18 ;
goto V_19;
}
V_8 = V_20 ;
while ( V_8 != NULL ) {
if ( F_4 ( & V_2 -> V_21 ,
& V_8 -> V_22 ) == 0 &&
V_8 -> V_4 == V_4 )
break;
V_8 = V_8 -> V_16 ;
}
if ( V_8 == NULL ) {
V_8 = F_5 ( sizeof( * V_8 ) , V_23 ) ;
if ( V_8 == NULL ) {
V_10 = - V_24 ;
goto V_19;
}
V_8 -> V_22 = V_2 -> V_21 ;
V_8 -> V_25 = NULL ;
V_8 -> V_26 = NULL ;
V_8 -> V_4 = V_4 ;
V_8 -> V_27 = 0 ;
V_8 -> V_28 = 0 ;
V_8 -> V_29 = 0 ;
V_8 -> V_17 = 0 ;
V_8 -> V_30 = V_31 ++ ;
V_8 -> V_32 = 0 ;
F_6 ( & V_8 -> V_33 ) ;
F_7 ( & V_8 -> V_34 ) ;
F_7 ( & V_8 -> V_35 ) ;
if ( V_2 -> V_36 != 0 ) {
V_8 -> V_25 =
F_5 ( sizeof( V_37 ) , V_23 ) ;
if ( V_8 -> V_25 == NULL ) {
F_8 ( V_8 ) ;
V_10 = - V_24 ;
goto V_19;
}
V_8 -> V_25 -> V_38 = V_2 -> V_36 ;
V_8 -> V_25 -> V_39 = - 1 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_36 ; V_9 ++ ) {
V_8 -> V_25 -> V_40 [ V_9 ] =
V_2 -> V_41 [ V_9 ] ;
V_8 -> V_25 -> V_42 [ V_9 ] = 0 ;
}
}
V_8 -> V_16 = V_20 ;
V_20 = V_8 ;
}
if ( V_5 == NULL ) {
V_6 = V_13 ;
V_7 = NULL ;
while ( V_6 != NULL ) {
if ( V_6 -> V_14 > V_2 -> V_14 ) {
V_7 = V_6 ;
V_6 = V_6 -> V_16 ;
} else {
break;
}
}
V_5 = F_5 ( sizeof( * V_5 ) , V_23 ) ;
if ( V_5 == NULL ) {
V_10 = - V_24 ;
goto V_19;
}
V_5 -> V_15 = V_2 -> V_15 ;
V_5 -> V_14 = V_2 -> V_14 ;
V_5 -> V_27 = 1 ;
V_5 -> V_17 = 0 ;
V_5 -> V_21 [ 0 ] = V_8 ;
if ( V_6 == NULL ) {
if ( V_7 == NULL ) {
V_13 = V_5 ;
V_5 -> V_16 = NULL ;
} else {
V_7 -> V_16 = V_5 ;
V_5 -> V_16 = NULL ;
}
} else {
if ( V_7 == NULL ) {
V_5 -> V_16 = V_13 ;
V_13 = V_5 ;
} else {
V_7 -> V_16 = V_5 ;
V_5 -> V_16 = V_6 ;
}
}
V_8 -> V_27 ++ ;
goto V_19;
}
if ( V_5 -> V_27 < 3 ) {
V_5 -> V_21 [ V_5 -> V_27 ] = V_8 ;
V_5 -> V_27 ++ ;
V_8 -> V_27 ++ ;
}
V_19:
F_9 ( & V_12 ) ;
F_9 ( & V_11 ) ;
return V_10 ;
}
static void F_10 ( struct V_5 * V_5 )
{
struct V_5 * V_43 ;
if ( ( V_43 = V_13 ) == V_5 ) {
V_13 = V_5 -> V_16 ;
F_8 ( V_5 ) ;
return;
}
while ( V_43 != NULL && V_43 -> V_16 != NULL ) {
if ( V_43 -> V_16 == V_5 ) {
V_43 -> V_16 = V_5 -> V_16 ;
F_8 ( V_5 ) ;
return;
}
V_43 = V_43 -> V_16 ;
}
}
static void F_11 ( struct V_8 * V_8 )
{
struct V_8 * V_43 ;
F_12 ( V_8 ) ;
F_13 ( V_8 ) ;
F_14 ( & V_8 -> V_33 ) ;
if ( ( V_43 = V_20 ) == V_8 ) {
V_20 = V_8 -> V_16 ;
if ( V_8 -> V_26 )
F_15 ( V_8 -> V_26 ) ;
F_8 ( V_8 -> V_25 ) ;
F_8 ( V_8 ) ;
return;
}
while ( V_43 != NULL && V_43 -> V_16 != NULL ) {
if ( V_43 -> V_16 == V_8 ) {
V_43 -> V_16 = V_8 -> V_16 ;
if ( V_8 -> V_26 )
F_15 ( V_8 -> V_26 ) ;
F_8 ( V_8 -> V_25 ) ;
F_8 ( V_8 ) ;
return;
}
V_43 = V_43 -> V_16 ;
}
}
static void F_16 ( struct V_2 * V_2 )
{
struct V_2 * V_43 ;
if ( V_2 -> V_44 != NULL )
V_2 -> V_44 -> V_28 -- ;
if ( V_2 -> V_45 != NULL )
V_2 -> V_45 -> V_28 -- ;
if ( ( V_43 = V_46 ) == V_2 ) {
V_46 = V_2 -> V_16 ;
F_8 ( V_2 ) ;
return;
}
while ( V_43 != NULL && V_43 -> V_16 != NULL ) {
if ( V_43 -> V_16 == V_2 ) {
V_43 -> V_16 = V_2 -> V_16 ;
F_8 ( V_2 ) ;
return;
}
V_43 = V_43 -> V_16 ;
}
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_5 ;
struct V_8 * V_8 ;
int V_9 , V_47 = 0 ;
F_2 ( & V_11 ) ;
F_2 ( & V_12 ) ;
V_5 = V_13 ;
while ( V_5 != NULL ) {
if ( ( V_5 -> V_14 == V_2 -> V_14 ) &&
( F_3 ( & V_2 -> V_15 , & V_5 -> V_15 ,
V_2 -> V_14 ) == 0 ) )
break;
V_5 = V_5 -> V_16 ;
}
if ( V_5 == NULL || V_5 -> V_17 ) {
V_47 = - V_18 ;
goto V_19;
}
V_8 = V_20 ;
while ( V_8 != NULL ) {
if ( F_4 ( & V_2 -> V_21 ,
& V_8 -> V_22 ) == 0 &&
V_8 -> V_4 == V_4 )
break;
V_8 = V_8 -> V_16 ;
}
if ( V_8 == NULL ) {
V_47 = - V_18 ;
goto V_19;
}
for ( V_9 = 0 ; V_9 < V_5 -> V_27 ; V_9 ++ ) {
if ( V_5 -> V_21 [ V_9 ] == V_8 ) {
V_8 -> V_27 -- ;
if ( V_8 -> V_27 == 0 && V_8 -> V_28 == 0 )
F_11 ( V_8 ) ;
V_5 -> V_27 -- ;
if ( V_5 -> V_27 == 0 ) {
F_10 ( V_5 ) ;
} else {
switch ( V_9 ) {
case 0 :
V_5 -> V_21 [ 0 ] =
V_5 -> V_21 [ 1 ] ;
case 1 :
V_5 -> V_21 [ 1 ] =
V_5 -> V_21 [ 2 ] ;
case 2 :
break;
}
}
goto V_19;
}
}
V_47 = - V_18 ;
V_19:
F_9 ( & V_12 ) ;
F_9 ( & V_11 ) ;
return V_47 ;
}
void F_18 ( void )
{
struct V_8 * V_48 ;
V_49 = F_5 ( sizeof( struct V_8 ) , V_50 ) ;
if ( ! V_49 )
return;
V_48 = V_49 ;
V_48 -> V_22 = V_51 ;
V_48 -> V_25 = NULL ;
V_48 -> V_26 = NULL ;
V_48 -> V_4 = NULL ;
V_48 -> V_27 = 0 ;
V_48 -> V_28 = 0 ;
V_48 -> V_29 = 1 ;
V_48 -> V_17 = 1 ;
V_48 -> V_30 = V_31 ++ ;
V_48 -> V_32 = 1 ;
F_6 ( & V_48 -> V_33 ) ;
F_7 ( & V_48 -> V_34 ) ;
F_7 ( & V_48 -> V_35 ) ;
F_2 ( & V_12 ) ;
V_48 -> V_16 = V_20 ;
V_20 = V_48 ;
F_9 ( & V_12 ) ;
}
int F_19 ( T_2 * V_15 )
{
struct V_5 * V_5 ;
int V_47 = 0 ;
F_2 ( & V_11 ) ;
V_5 = V_13 ;
while ( V_5 != NULL ) {
if ( ( V_5 -> V_14 == 10 ) &&
( F_3 ( V_15 , & V_5 -> V_15 , 10 ) == 0 ) &&
V_5 -> V_17 )
break;
V_5 = V_5 -> V_16 ;
}
if ( V_5 != NULL )
goto V_19;
if ( ( V_5 = F_5 ( sizeof( * V_5 ) , V_23 ) ) == NULL ) {
V_47 = - V_24 ;
goto V_19;
}
V_5 -> V_15 = * V_15 ;
V_5 -> V_14 = 10 ;
V_5 -> V_27 = 1 ;
V_5 -> V_17 = 1 ;
V_5 -> V_21 [ 0 ] = V_49 ;
V_5 -> V_16 = V_13 ;
V_13 = V_5 ;
V_49 -> V_27 ++ ;
V_19:
F_9 ( & V_11 ) ;
return V_47 ;
}
void F_20 ( T_2 * V_15 )
{
struct V_5 * V_5 ;
F_2 ( & V_11 ) ;
V_5 = V_13 ;
while ( V_5 != NULL ) {
if ( ( V_5 -> V_14 == 10 ) &&
( F_3 ( V_15 , & V_5 -> V_15 , 10 ) == 0 ) &&
V_5 -> V_17 )
break;
V_5 = V_5 -> V_16 ;
}
if ( V_5 == NULL )
goto V_19;
F_10 ( V_5 ) ;
V_49 -> V_27 -- ;
V_19:
F_9 ( & V_11 ) ;
}
void F_21 ( struct V_3 * V_4 )
{
struct V_8 * V_43 , * V_8 ;
struct V_5 * V_52 , * V_5 ;
int V_9 ;
F_2 ( & V_11 ) ;
F_2 ( & V_12 ) ;
V_8 = V_20 ;
while ( V_8 != NULL ) {
V_43 = V_8 ;
V_8 = V_8 -> V_16 ;
if ( V_43 -> V_4 != V_4 )
continue;
V_5 = V_13 ;
while ( V_5 != NULL ) {
V_52 = V_5 ;
V_5 = V_5 -> V_16 ;
for ( V_9 = 0 ; V_9 < V_52 -> V_27 ; V_9 ++ ) {
if ( V_52 -> V_21 [ V_9 ] != V_43 )
continue;
V_52 -> V_27 -- ;
switch ( V_9 ) {
case 0 :
V_52 -> V_21 [ 0 ] = V_52 -> V_21 [ 1 ] ;
case 1 :
V_52 -> V_21 [ 1 ] = V_52 -> V_21 [ 2 ] ;
case 2 :
break;
}
}
if ( V_52 -> V_27 <= 0 )
F_10 ( V_52 ) ;
}
F_11 ( V_43 ) ;
}
F_9 ( & V_12 ) ;
F_9 ( & V_11 ) ;
}
static int F_22 ( void )
{
struct V_8 * V_43 , * V_8 ;
struct V_5 * V_52 , * V_5 ;
F_2 ( & V_11 ) ;
F_2 ( & V_12 ) ;
V_8 = V_20 ;
V_5 = V_13 ;
while ( V_5 != NULL ) {
V_52 = V_5 ;
V_5 = V_5 -> V_16 ;
if ( ! V_52 -> V_17 )
F_10 ( V_52 ) ;
}
while ( V_8 != NULL ) {
V_43 = V_8 ;
V_8 = V_8 -> V_16 ;
if ( V_43 -> V_28 == 0 && ! V_43 -> V_17 ) {
V_43 -> V_27 = 0 ;
F_11 ( V_43 ) ;
}
}
F_9 ( & V_12 ) ;
F_9 ( & V_11 ) ;
return 0 ;
}
static struct V_3 * F_23 ( char * V_53 )
{
struct V_3 * V_4 ;
if ( ( V_4 = F_24 ( & V_54 , V_53 ) ) == NULL )
return NULL ;
if ( ( V_4 -> V_55 & V_56 ) && V_4 -> type == V_57 )
return V_4 ;
return NULL ;
}
struct V_3 * F_25 ( void )
{
struct V_3 * V_4 , * V_58 = NULL ;
F_26 () ;
F_27 (&init_net, dev) {
if ( ( V_4 -> V_55 & V_56 ) && V_4 -> type == V_59 )
if ( V_58 == NULL || strncmp ( V_4 -> V_60 , V_58 -> V_60 , 3 ) < 0 )
V_58 = V_4 ;
}
F_28 () ;
return V_58 ;
}
struct V_3 * F_29 ( T_2 * V_61 )
{
struct V_3 * V_4 ;
F_26 () ;
F_27 (&init_net, dev) {
if ( ( V_4 -> V_55 & V_56 ) && V_4 -> type == V_59 && F_30 ( V_61 , ( T_2 * ) V_4 -> V_62 ) == 0 ) {
F_31 ( V_4 ) ;
goto V_19;
}
}
V_4 = NULL ;
V_19:
F_28 () ;
return V_4 ;
}
static int F_32 ( T_2 * V_61 )
{
struct V_3 * V_4 ;
F_26 () ;
F_27 (&init_net, dev) {
if ( ( V_4 -> V_55 & V_56 ) && V_4 -> type == V_59 && F_30 ( V_61 , ( T_2 * ) V_4 -> V_62 ) == 0 )
goto V_19;
}
V_4 = NULL ;
V_19:
F_28 () ;
return V_4 != NULL ;
}
struct V_2 * F_33 ( unsigned int V_63 , struct V_8 * V_64 )
{
struct V_2 * V_2 ;
for ( V_2 = V_46 ; V_2 != NULL ; V_2 = V_2 -> V_16 )
if ( ( V_2 -> V_44 == V_64 && V_2 -> V_65 == V_63 ) ||
( V_2 -> V_45 == V_64 && V_2 -> V_66 == V_63 ) )
return V_2 ;
return NULL ;
}
struct V_8 * F_34 ( T_2 * V_61 , unsigned char * V_67 ,
unsigned char * V_68 , int V_69 )
{
struct V_8 * V_10 = NULL ;
struct V_5 * V_70 ;
int V_71 = 0 ;
int V_9 ;
if ( ! V_69 ) F_2 ( & V_11 ) ;
for ( V_70 = V_13 ; V_70 != NULL ; V_70 = V_70 -> V_16 ) {
if ( F_3 ( V_61 , & V_70 -> V_15 , V_70 -> V_14 ) == 0 ) {
for ( V_9 = 0 ; V_9 < V_70 -> V_27 ; V_9 ++ ) {
if ( V_70 -> V_21 [ V_9 ] -> V_32 ) {
V_10 = V_70 -> V_21 [ V_9 ] ;
goto V_19;
}
}
}
}
if ( ! V_69 ) {
for ( V_70 = V_13 ; V_70 != NULL ; V_70 = V_70 -> V_16 ) {
if ( F_3 ( V_61 , & V_70 -> V_15 , V_70 -> V_14 ) == 0 ) {
for ( V_9 = 0 ; V_9 < V_70 -> V_27 ; V_9 ++ ) {
if ( ! F_35 ( V_70 -> V_21 [ V_9 ] ) ) {
V_10 = V_70 -> V_21 [ V_9 ] ;
V_71 = 0 ;
goto V_19;
}
V_71 = 1 ;
}
}
}
}
if ( V_71 ) {
* V_67 = V_72 ;
* V_68 = 0 ;
} else {
* V_67 = V_73 ;
* V_68 = 0 ;
}
V_19:
if ( ! V_69 ) F_9 ( & V_11 ) ;
return V_10 ;
}
int F_36 ( unsigned int V_74 , void T_3 * V_75 )
{
struct V_1 V_2 ;
struct V_3 * V_4 ;
int V_47 ;
switch ( V_74 ) {
case V_76 :
if ( F_37 ( & V_2 , V_75 , sizeof( struct V_1 ) ) )
return - V_77 ;
if ( ( V_4 = F_23 ( V_2 . V_78 ) ) == NULL )
return - V_18 ;
if ( F_32 ( & V_2 . V_15 ) )
return - V_18 ;
if ( V_2 . V_14 > 10 )
return - V_18 ;
if ( V_2 . V_36 > V_79 )
return - V_18 ;
V_47 = F_1 ( & V_2 , V_4 ) ;
return V_47 ;
case V_80 :
if ( F_37 ( & V_2 , V_75 , sizeof( struct V_1 ) ) )
return - V_77 ;
if ( ( V_4 = F_23 ( V_2 . V_78 ) ) == NULL )
return - V_18 ;
V_47 = F_17 ( & V_2 , V_4 ) ;
return V_47 ;
case V_81 :
return F_22 () ;
default:
return - V_18 ;
}
return 0 ;
}
static void F_38 ( struct V_8 * V_8 )
{
struct V_2 * V_2 , * V_43 ;
V_8 -> V_32 = 0 ;
F_13 ( V_8 ) ;
F_39 ( V_8 ) ;
F_14 ( & V_8 -> V_33 ) ;
F_2 ( & V_82 ) ;
V_2 = V_46 ;
while ( V_2 != NULL ) {
if ( ( V_2 -> V_44 == V_8 && V_2 -> V_45 == V_8 ) ||
( V_2 -> V_44 == V_8 && V_2 -> V_45 == NULL ) ||
( V_2 -> V_45 == V_8 && V_2 -> V_44 == NULL ) ) {
V_43 = V_2 -> V_16 ;
F_16 ( V_2 ) ;
V_2 = V_43 ;
continue;
}
if ( V_2 -> V_44 == V_8 ) {
V_2 -> V_44 -> V_28 -- ;
V_2 -> V_44 = NULL ;
F_40 ( V_2 -> V_45 , V_2 -> V_66 , V_72 , 0 ) ;
}
if ( V_2 -> V_45 == V_8 ) {
V_2 -> V_45 -> V_28 -- ;
V_2 -> V_45 = NULL ;
F_40 ( V_2 -> V_44 , V_2 -> V_65 , V_72 , 0 ) ;
}
V_2 = V_2 -> V_16 ;
}
F_9 ( & V_82 ) ;
}
void F_41 ( T_4 * V_26 , int V_83 )
{
struct V_8 * V_8 ;
F_2 ( & V_12 ) ;
V_8 = V_20 ;
while ( V_8 != NULL ) {
if ( V_8 -> V_26 == V_26 )
break;
V_8 = V_8 -> V_16 ;
}
if ( V_8 != NULL ) {
V_8 -> V_26 = NULL ;
F_15 ( V_26 ) ;
F_38 ( V_8 ) ;
F_42 ( V_8 ) ;
}
F_9 ( & V_12 ) ;
}
void F_43 ( struct V_3 * V_4 )
{
struct V_8 * V_8 ;
for ( V_8 = V_20 ; V_8 != NULL ; V_8 = V_8 -> V_16 ) {
if ( V_8 -> V_4 == V_4 ) {
F_38 ( V_8 ) ;
F_42 ( V_8 ) ;
}
}
}
int F_44 ( struct V_84 * V_85 , T_4 * V_26 )
{
struct V_8 * V_8 , * V_86 ;
struct V_2 * V_2 ;
struct V_87 V_88 ;
T_2 * V_89 , * V_90 ;
struct V_91 * V_92 ;
unsigned short V_93 ;
unsigned int V_63 , V_94 ;
unsigned char V_67 , V_68 ;
struct V_3 * V_4 ;
int V_10 = 0 ;
char V_95 [ 11 ] ;
#if 0
if (call_in_firewall(PF_ROSE, skb->dev, skb->data, NULL, &skb) != FW_ACCEPT)
return res;
#endif
if ( V_85 -> V_96 < V_97 )
return V_10 ;
V_93 = V_85 -> V_98 [ 2 ] ;
V_63 = ( ( V_85 -> V_98 [ 0 ] << 8 ) & 0xF00 ) + ( ( V_85 -> V_98 [ 1 ] << 0 ) & 0x0FF ) ;
if ( V_93 == V_99 &&
( V_85 -> V_96 <= V_100 ||
V_85 -> V_98 [ V_101 ] !=
V_102 ) )
return V_10 ;
V_89 = ( T_2 * ) ( V_85 -> V_98 + V_103 ) ;
V_90 = ( T_2 * ) ( V_85 -> V_98 + V_104 ) ;
F_2 ( & V_12 ) ;
F_2 ( & V_82 ) ;
V_8 = V_20 ;
while ( V_8 != NULL ) {
if ( F_4 ( & V_26 -> V_90 , & V_8 -> V_22 ) == 0 &&
V_26 -> V_105 -> V_4 == V_8 -> V_4 )
break;
V_8 = V_8 -> V_16 ;
}
if ( V_8 == NULL ) {
F_45 ( L_1 ,
F_46 ( V_95 , & V_26 -> V_90 ) ) ;
goto V_19;
}
F_12 ( V_8 ) ;
if ( V_63 == 0 ) {
F_47 ( V_85 , V_8 , V_93 ) ;
goto V_19;
}
if ( ( V_92 = F_48 ( V_63 , V_8 ) ) != NULL ) {
if ( V_93 == V_99 ) {
struct V_106 * V_107 = F_49 ( V_92 ) ;
F_50 ( V_92 ) ;
V_107 -> V_67 = V_108 ;
V_107 -> V_68 = 0 ;
V_107 -> V_21 -> V_28 -- ;
V_107 -> V_21 = NULL ;
V_107 -> V_63 = 0 ;
V_107 -> V_109 = V_110 ;
V_92 -> V_111 = V_112 ;
V_92 -> V_113 = 0 ;
V_92 -> V_114 |= V_115 ;
if ( ! F_51 ( V_92 , V_116 ) ) {
V_92 -> V_117 ( V_92 ) ;
F_52 ( V_92 , V_116 ) ;
}
}
else {
F_53 ( V_85 ) ;
V_10 = F_54 ( V_92 , V_85 ) ;
goto V_19;
}
}
if ( V_93 == V_99 )
if ( ( V_4 = F_29 ( V_90 ) ) != NULL ) {
V_10 = F_55 ( V_85 , V_4 , V_8 , V_63 ) ;
F_56 ( V_4 ) ;
goto V_19;
}
if ( ! V_118 ) {
F_40 ( V_8 , V_63 , V_73 , 0 ) ;
goto V_19;
}
V_2 = V_46 ;
while ( V_2 != NULL ) {
if ( V_2 -> V_65 == V_63 &&
V_2 -> V_44 == V_8 ) {
if ( V_93 == V_99 ) {
F_16 ( V_2 ) ;
break;
} else if ( V_2 -> V_45 != NULL ) {
V_85 -> V_98 [ 0 ] &= 0xF0 ;
V_85 -> V_98 [ 0 ] |= ( V_2 -> V_66 >> 8 ) & 0x0F ;
V_85 -> V_98 [ 1 ] = ( V_2 -> V_66 >> 0 ) & 0xFF ;
F_57 ( V_85 , V_2 -> V_45 ) ;
if ( V_93 == V_119 )
F_16 ( V_2 ) ;
V_10 = 1 ;
goto V_19;
} else {
if ( V_93 == V_119 )
F_16 ( V_2 ) ;
goto V_19;
}
}
if ( V_2 -> V_66 == V_63 &&
V_2 -> V_45 == V_8 ) {
if ( V_93 == V_99 ) {
F_16 ( V_2 ) ;
break;
} else if ( V_2 -> V_44 != NULL ) {
V_85 -> V_98 [ 0 ] &= 0xF0 ;
V_85 -> V_98 [ 0 ] |= ( V_2 -> V_65 >> 8 ) & 0x0F ;
V_85 -> V_98 [ 1 ] = ( V_2 -> V_65 >> 0 ) & 0xFF ;
F_57 ( V_85 , V_2 -> V_44 ) ;
if ( V_93 == V_119 )
F_16 ( V_2 ) ;
V_10 = 1 ;
goto V_19;
} else {
if ( V_93 == V_119 )
F_16 ( V_2 ) ;
goto V_19;
}
}
V_2 = V_2 -> V_16 ;
}
if ( V_93 != V_99 ) {
V_10 = 0 ;
goto V_19;
}
memset ( & V_88 , 0x00 , sizeof( struct V_87 ) ) ;
if ( ! F_58 ( V_85 -> V_98 + V_100 ,
V_85 -> V_96 - V_100 ,
& V_88 ) ) {
F_40 ( V_8 , V_63 , V_120 , 76 ) ;
goto V_19;
}
V_2 = V_46 ;
while ( V_2 != NULL ) {
if ( V_2 -> rand == V_88 . rand &&
F_30 ( V_89 , & V_2 -> V_89 ) == 0 &&
F_4 ( & V_88 . V_121 , & V_2 -> V_122 ) == 0 &&
F_4 ( & V_88 . V_123 , & V_2 -> V_121 ) == 0 ) {
F_40 ( V_8 , V_63 , V_73 , 120 ) ;
goto V_19;
}
V_2 = V_2 -> V_16 ;
}
if ( ( V_86 = F_34 ( V_90 , & V_67 , & V_68 , 1 ) ) == NULL ) {
F_40 ( V_8 , V_63 , V_67 , V_68 ) ;
goto V_19;
}
if ( ( V_94 = F_59 ( V_86 ) ) == 0 ) {
F_40 ( V_8 , V_63 , V_108 , 71 ) ;
goto V_19;
}
if ( ( V_2 = F_5 ( sizeof( * V_2 ) , V_23 ) ) == NULL ) {
F_40 ( V_8 , V_63 , V_108 , 120 ) ;
goto V_19;
}
V_2 -> V_65 = V_63 ;
V_2 -> V_89 = * V_89 ;
V_2 -> V_90 = * V_90 ;
V_2 -> V_122 = V_88 . V_121 ;
V_2 -> V_121 = V_88 . V_123 ;
V_2 -> rand = V_88 . rand ;
V_2 -> V_44 = V_8 ;
V_2 -> V_66 = V_94 ;
V_2 -> V_45 = V_86 ;
V_2 -> V_44 -> V_28 ++ ;
V_2 -> V_45 -> V_28 ++ ;
V_2 -> V_16 = V_46 ;
V_46 = V_2 ;
V_85 -> V_98 [ 0 ] &= 0xF0 ;
V_85 -> V_98 [ 0 ] |= ( V_2 -> V_66 >> 8 ) & 0x0F ;
V_85 -> V_98 [ 1 ] = ( V_2 -> V_66 >> 0 ) & 0xFF ;
F_57 ( V_85 , V_2 -> V_45 ) ;
V_10 = 1 ;
V_19:
F_9 ( & V_82 ) ;
F_9 ( & V_12 ) ;
return V_10 ;
}
static void * F_60 ( struct V_124 * V_125 , T_5 * V_126 )
__acquires( V_11 )
{
struct V_5 * V_5 ;
int V_9 = 1 ;
F_2 ( & V_11 ) ;
if ( * V_126 == 0 )
return V_127 ;
for ( V_5 = V_13 ; V_5 && V_9 < * V_126 ;
V_5 = V_5 -> V_16 , ++ V_9 ) ;
return ( V_9 == * V_126 ) ? V_5 : NULL ;
}
static void * F_61 ( struct V_124 * V_125 , void * V_128 , T_5 * V_126 )
{
++ * V_126 ;
return ( V_128 == V_127 ) ? V_13
: ( (struct V_5 * ) V_128 ) -> V_16 ;
}
static void F_62 ( struct V_124 * V_125 , void * V_128 )
__releases( V_11 )
{
F_9 ( & V_11 ) ;
}
static int F_63 ( struct V_124 * V_125 , void * V_128 )
{
char V_129 [ 11 ] ;
int V_9 ;
if ( V_128 == V_127 )
F_64 ( V_125 , L_2 ) ;
else {
const struct V_5 * V_5 = V_128 ;
F_65 ( V_125 , L_3 ,
F_66 ( V_129 , & V_5 -> V_15 ) ,
V_5 -> V_14 ,
V_5 -> V_27 ) ;
for ( V_9 = 0 ; V_9 < V_5 -> V_27 ; V_9 ++ )
F_65 ( V_125 , L_4 ,
V_5 -> V_21 [ V_9 ] -> V_30 ) ;
F_64 ( V_125 , L_5 ) ;
}
return 0 ;
}
static int F_67 ( struct V_130 * V_130 , struct V_131 * V_131 )
{
return F_68 ( V_131 , & V_132 ) ;
}
static void * F_69 ( struct V_124 * V_125 , T_5 * V_126 )
__acquires( V_12 )
{
struct V_8 * V_8 ;
int V_9 = 1 ;
F_2 ( & V_12 ) ;
if ( * V_126 == 0 )
return V_127 ;
for ( V_8 = V_20 ; V_8 && V_9 < * V_126 ;
V_8 = V_8 -> V_16 , ++ V_9 ) ;
return ( V_9 == * V_126 ) ? V_8 : NULL ;
}
static void * F_70 ( struct V_124 * V_125 , void * V_128 , T_5 * V_126 )
{
++ * V_126 ;
return ( V_128 == V_127 ) ? V_20
: ( (struct V_8 * ) V_128 ) -> V_16 ;
}
static void F_71 ( struct V_124 * V_125 , void * V_128 )
__releases( V_12 )
{
F_9 ( & V_12 ) ;
}
static int F_72 ( struct V_124 * V_125 , void * V_128 )
{
char V_95 [ 11 ] ;
int V_9 ;
if ( V_128 == V_127 )
F_64 ( V_125 ,
L_6 ) ;
else {
struct V_8 * V_8 = V_128 ;
F_65 ( V_125 , L_7 ,
V_8 -> V_30 ,
( V_8 -> V_17 ) ? L_8 : F_46 ( V_95 , & V_8 -> V_22 ) ,
V_8 -> V_4 ? V_8 -> V_4 -> V_60 : L_9 ,
V_8 -> V_27 ,
V_8 -> V_28 ,
( V_8 -> V_29 ) ? L_10 : L_11 ,
( V_8 -> V_32 ) ? L_12 : L_13 ,
F_73 ( & V_8 -> V_35 ) / V_133 ,
F_73 ( & V_8 -> V_34 ) / V_133 ) ;
if ( V_8 -> V_25 != NULL ) {
for ( V_9 = 0 ; V_9 < V_8 -> V_25 -> V_38 ; V_9 ++ )
F_65 ( V_125 , L_14 , F_46 ( V_95 , & V_8 -> V_25 -> V_40 [ V_9 ] ) ) ;
}
F_64 ( V_125 , L_5 ) ;
}
return 0 ;
}
static int F_74 ( struct V_130 * V_130 , struct V_131 * V_131 )
{
return F_68 ( V_131 , & V_134 ) ;
}
static void * F_75 ( struct V_124 * V_125 , T_5 * V_126 )
__acquires( V_82 )
{
struct V_2 * V_2 ;
int V_9 = 1 ;
F_2 ( & V_82 ) ;
if ( * V_126 == 0 )
return V_127 ;
for ( V_2 = V_46 ; V_2 && V_9 < * V_126 ;
V_2 = V_2 -> V_16 , ++ V_9 ) ;
return ( V_9 == * V_126 ) ? V_2 : NULL ;
}
static void * F_76 ( struct V_124 * V_125 , void * V_128 , T_5 * V_126 )
{
++ * V_126 ;
return ( V_128 == V_127 ) ? V_46
: ( (struct V_2 * ) V_128 ) -> V_16 ;
}
static void F_77 ( struct V_124 * V_125 , void * V_128 )
__releases( V_82 )
{
F_9 ( & V_82 ) ;
}
static int F_78 ( struct V_124 * V_125 , void * V_128 )
{
char V_95 [ 11 ] , V_129 [ 11 ] ;
if ( V_128 == V_127 )
F_64 ( V_125 ,
L_15 ) ;
else {
struct V_2 * V_2 = V_128 ;
if ( V_2 -> V_44 )
F_65 ( V_125 ,
L_16 ,
V_2 -> V_65 ,
F_66 ( V_129 , & V_2 -> V_89 ) ,
F_46 ( V_95 , & V_2 -> V_122 ) ,
V_2 -> V_44 -> V_30 ) ;
else
F_64 ( V_125 ,
L_17 ) ;
if ( V_2 -> V_45 )
F_65 ( V_125 ,
L_18 ,
V_2 -> V_66 ,
F_66 ( V_129 , & V_2 -> V_90 ) ,
F_46 ( V_95 , & V_2 -> V_121 ) ,
V_2 -> V_45 -> V_30 ) ;
else
F_64 ( V_125 ,
L_19 ) ;
}
return 0 ;
}
static int F_79 ( struct V_130 * V_130 , struct V_131 * V_131 )
{
return F_68 ( V_131 , & V_135 ) ;
}
void T_6 F_80 ( void )
{
struct V_8 * V_43 , * V_8 = V_20 ;
struct V_5 * V_52 , * V_5 = V_13 ;
struct V_2 * V_136 , * V_2 = V_46 ;
while ( V_8 != NULL ) {
V_43 = V_8 ;
V_8 = V_8 -> V_16 ;
F_11 ( V_43 ) ;
}
while ( V_5 != NULL ) {
V_52 = V_5 ;
V_5 = V_5 -> V_16 ;
F_10 ( V_52 ) ;
}
while ( V_2 != NULL ) {
V_136 = V_2 ;
V_2 = V_2 -> V_16 ;
F_16 ( V_136 ) ;
}
}
