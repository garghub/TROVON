static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 -> V_4 ;
switch ( V_1 -> V_5 ) {
case 0 :
break;
case - V_6 :
case - V_7 :
case - V_8 :
case - V_9 :
goto free;
default:
break;
}
if ( V_3 ) {
F_2 ( V_3 -> V_10 -> V_11 ,
V_3 -> V_12 , true ) ;
F_3 ( V_3 ) ;
}
return;
free:
F_4 ( V_3 -> V_12 ) ;
F_3 ( V_3 ) ;
}
static int F_5 ( struct V_13 * V_10 ,
struct V_14 * V_12 )
{
struct V_1 * V_1 ;
struct V_2 * V_3 ;
int V_15 = 0 ;
V_1 = F_6 ( 0 , V_16 ) ;
if ( V_1 == NULL )
return - V_17 ;
V_3 = F_7 ( sizeof( * V_3 ) , V_16 ) ;
if ( V_3 == NULL ) {
F_8 ( V_1 ) ;
return - V_17 ;
}
V_3 -> V_12 = V_12 ;
V_3 -> V_10 = V_10 ;
F_9 ( V_1 , V_10 -> V_18 ,
F_10 ( V_10 -> V_18 , V_19 ) ,
V_12 -> V_20 , V_12 -> V_21 ,
F_1 , V_3 ) ;
F_11 ( V_1 , & V_10 -> V_22 ) ;
V_15 = F_12 ( V_1 , V_16 ) ;
if ( V_15 ) {
F_13 ( V_1 ) ;
F_3 ( V_3 ) ;
}
F_8 ( V_1 ) ;
return V_15 ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 -> V_4 ;
struct V_13 * V_10 ;
bool V_23 = true ;
if ( ! V_3 || ! V_3 -> V_12 || ! V_3 -> V_10 )
return;
V_10 = V_3 -> V_10 ;
switch ( V_1 -> V_5 ) {
case 0 :
break;
case - V_6 :
case - V_7 :
case - V_8 :
case - V_9 :
V_23 = false ;
F_15 ( & V_10 -> V_24 . V_25 ) ;
if ( V_10 -> V_24 . V_26 & V_27 ) {
F_16 ( & V_10 -> V_24 . V_25 ) ;
F_17 ( V_3 -> V_12 ) ;
F_3 ( V_3 ) ;
return;
}
F_16 ( & V_10 -> V_24 . V_25 ) ;
break;
default:
V_23 = false ;
break;
}
F_18 ( V_3 -> V_12 , 4 ) ;
F_2 ( V_3 -> V_10 -> V_11 ,
V_3 -> V_12 , V_23 ) ;
F_3 ( V_3 ) ;
}
static int F_19 ( struct V_13 * V_10 ,
struct V_14 * V_12 )
{
struct V_1 * V_1 ;
struct V_2 * V_3 ;
int V_15 = 0 ;
T_1 * V_28 ;
V_1 = F_6 ( 0 , V_29 ) ;
if ( V_1 == NULL )
return - V_17 ;
V_3 = F_7 ( sizeof( * V_3 ) , V_29 ) ;
if ( V_3 == NULL ) {
F_8 ( V_1 ) ;
return - V_17 ;
}
V_3 -> V_12 = V_12 ;
V_3 -> V_10 = V_10 ;
V_28 = ( T_1 * ) F_20 ( V_12 , 4 ) ;
* V_28 ++ = F_21 ( V_12 -> V_21 - 4 ) ;
* V_28 ++ = F_21 ( V_30 ) ;
F_9 ( V_1 , V_10 -> V_18 ,
F_10 ( V_10 -> V_18 , V_31 ) ,
V_12 -> V_20 , V_12 -> V_21 ,
F_14 , V_3 ) ;
F_11 ( V_1 , & V_10 -> V_32 ) ;
V_15 = F_12 ( V_1 , V_29 ) ;
if ( V_15 ) {
F_13 ( V_1 ) ;
F_3 ( V_3 ) ;
}
F_8 ( V_1 ) ;
return V_15 ;
}
static inline void F_22 ( struct V_13 * V_10 ,
struct V_33 * V_34 )
{
struct V_14 * V_12 ;
while ( ( V_12 = F_23 ( V_34 ) ) != NULL ) {
F_17 ( V_12 ) ;
}
}
static inline void F_24 ( struct V_13 * V_10 ,
struct V_33 * V_35 ,
bool V_23 )
{
struct V_14 * V_12 ;
while ( ( V_12 = F_23 ( V_35 ) ) != NULL ) {
F_2 ( V_10 -> V_11 ,
V_12 , V_23 ) ;
if ( V_23 )
F_25 ( V_36 ) ;
else
F_25 ( V_37 ) ;
}
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_38 * V_38 = (struct V_38 * ) V_1 -> V_4 ;
struct V_13 * V_10 ;
bool V_23 = true ;
if ( ! V_38 || ! V_38 -> V_10 )
return;
V_10 = V_38 -> V_10 ;
switch ( V_1 -> V_5 ) {
case 0 :
break;
case - V_6 :
case - V_7 :
case - V_8 :
case - V_9 :
V_23 = false ;
F_15 ( & V_10 -> V_24 . V_25 ) ;
if ( V_10 -> V_24 . V_26 & V_27 ) {
F_16 ( & V_10 -> V_24 . V_25 ) ;
F_22 ( V_10 , & V_38 -> V_39 ) ;
return;
}
F_16 ( & V_10 -> V_24 . V_25 ) ;
break;
default:
V_23 = false ;
break;
}
F_24 ( V_10 , & V_38 -> V_39 , V_23 ) ;
V_38 -> V_21 = V_38 -> V_40 = 0 ;
F_27 ( & V_38 -> V_39 ) ;
F_15 ( & V_10 -> V_24 . V_25 ) ;
F_28 ( & V_38 -> V_34 , & V_10 -> V_24 . V_38 ) ;
V_10 -> V_24 . V_41 ++ ;
if ( ! ( V_10 -> V_24 . V_26 & V_42 ) )
F_29 ( V_10 ) ;
F_25 ( V_43 ) ;
F_16 ( & V_10 -> V_24 . V_25 ) ;
}
static int F_29 ( struct V_13 * V_10 )
{
struct V_38 * V_38 = NULL ;
struct V_14 * V_44 = NULL ;
int V_15 = 0 , V_45 ;
T_2 V_46 = 0 ;
T_3 * V_47 ;
T_1 * V_28 ;
if ( V_10 -> V_24 . V_46 == 0 )
return 0 ;
if ( F_30 ( & V_10 -> V_24 . V_38 ) )
return 0 ;
V_38 = F_31 ( & V_10 -> V_24 . V_38 , struct V_38 , V_34 ) ;
F_28 ( & V_38 -> V_34 , & V_10 -> V_24 . V_48 ) ;
V_10 -> V_24 . V_41 -- ;
V_46 = F_32 ( T_2 , V_10 -> V_24 . V_46 , V_49 ) ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ ) {
V_44 = F_23 ( & V_10 -> V_24 . V_50 ) ;
F_33 ( ! V_44 ) ;
V_10 -> V_24 . V_46 -- ;
V_47 = V_38 -> V_47 ;
V_47 += V_38 -> V_40 ;
V_28 = ( T_1 * ) V_47 ;
* V_28 ++ = F_21 ( V_44 -> V_21 ) ;
* V_28 ++ = F_21 ( V_30 ) ;
V_47 += 4 ;
memcpy ( V_47 , V_44 -> V_20 , V_44 -> V_21 ) ;
V_38 -> V_21 = V_44 -> V_21 + 4 ;
if ( V_45 < ( V_46 - 1 ) )
V_38 -> V_40 += ( ( ( V_38 -> V_21 - 1 ) / 4 ) + 1 ) * 4 ;
if ( V_45 == ( V_46 - 1 ) )
V_38 -> V_21 += V_38 -> V_40 ;
F_34 ( & V_38 -> V_39 , V_44 ) ;
F_25 ( V_51 ) ;
}
F_9 ( V_38 -> V_1 , V_10 -> V_18 ,
F_10 ( V_10 -> V_18 , V_31 ) ,
V_38 -> V_47 , V_38 -> V_21 ,
F_26 , V_38 ) ;
V_15 = F_12 ( V_38 -> V_1 , V_29 ) ;
if ( V_15 ) {
V_38 -> V_21 = V_38 -> V_40 = 0 ;
F_24 ( V_10 , & V_38 -> V_39 , false ) ;
F_27 ( & V_38 -> V_39 ) ;
F_28 ( & V_38 -> V_34 , & V_10 -> V_24 . V_38 ) ;
V_10 -> V_24 . V_41 ++ ;
}
if ( ! V_15 )
F_25 ( V_52 ) ;
return V_15 ;
}
static int F_35 ( struct V_13 * V_10 , struct V_14 * V_12 )
{
struct V_53 * V_54 ;
unsigned long V_26 ;
int V_15 = 0 ;
F_36 ( & V_10 -> V_24 . V_25 , V_26 ) ;
if ( V_10 -> V_24 . V_26 & V_42 ) {
F_37 ( & V_10 -> V_24 . V_25 , V_26 ) ;
return - V_8 ;
}
if ( V_10 -> V_24 . V_46 > V_55 ) {
F_37 ( & V_10 -> V_24 . V_25 , V_26 ) ;
return - V_17 ;
}
F_37 ( & V_10 -> V_24 . V_25 , V_26 ) ;
V_54 = F_38 ( V_12 ) ;
if ( ( V_54 -> type == V_56 ) ||
( V_54 -> type == V_57 ) ) {
V_15 = F_19 ( V_10 , V_12 ) ;
}
F_36 ( & V_10 -> V_24 . V_25 , V_26 ) ;
if ( ( V_54 -> type == V_58 ) ||
( V_54 -> type == V_59 ) ) {
F_34 ( & V_10 -> V_24 . V_50 , V_12 ) ;
V_10 -> V_24 . V_46 ++ ;
}
if ( ( V_10 -> V_24 . V_41 == V_60 ) &&
( V_10 -> V_24 . V_46 < 2 ) ) {
F_29 ( V_10 ) ;
}
F_37 ( & V_10 -> V_24 . V_25 , V_26 ) ;
return V_15 ;
}
static void F_39 ( void * V_61 )
{
struct V_13 * V_10 = (struct V_13 * ) V_61 ;
unsigned long V_26 ;
V_10 -> V_26 |= V_62 ;
F_36 ( & V_10 -> V_24 . V_25 , V_26 ) ;
V_10 -> V_24 . V_26 &= ~ V_42 ;
F_37 ( & V_10 -> V_24 . V_25 , V_26 ) ;
}
static void F_40 ( void * V_61 )
{
struct V_13 * V_10 = (struct V_13 * ) V_61 ;
struct V_38 * V_38 = NULL , * V_63 = NULL ;
unsigned long V_26 ;
F_36 ( & V_10 -> V_24 . V_25 , V_26 ) ;
F_24 ( V_10 , & V_10 -> V_24 . V_50 , false ) ;
V_10 -> V_24 . V_46 = 0 ;
V_10 -> V_24 . V_26 |= V_42 ;
F_37 ( & V_10 -> V_24 . V_25 , V_26 ) ;
F_41 (tx_buf, tx_buf_tmp,
&hif_dev->tx.tx_pending, list) {
F_42 ( V_38 -> V_1 ) ;
}
F_43 ( & V_10 -> V_32 ) ;
}
static int F_44 ( void * V_61 , T_3 V_64 , struct V_14 * V_12 )
{
struct V_13 * V_10 = (struct V_13 * ) V_61 ;
int V_15 = 0 ;
switch ( V_64 ) {
case V_31 :
V_15 = F_35 ( V_10 , V_12 ) ;
break;
case V_19 :
V_15 = F_5 ( V_10 , V_12 ) ;
break;
default:
F_45 ( & V_10 -> V_18 -> V_65 ,
L_1 , V_64 ) ;
V_15 = - V_66 ;
break;
}
return V_15 ;
}
static inline bool F_46 ( struct V_14 * V_12 , T_3 V_67 )
{
struct V_53 * V_54 ;
V_54 = F_38 ( V_12 ) ;
if ( ( V_54 -> type == V_59 ) &&
( V_54 -> V_68 == V_67 ) )
return true ;
return false ;
}
static void F_47 ( void * V_61 , T_3 V_67 )
{
struct V_13 * V_10 = (struct V_13 * ) V_61 ;
struct V_14 * V_12 , * V_69 ;
unsigned long V_26 ;
F_36 ( & V_10 -> V_24 . V_25 , V_26 ) ;
F_48 (&hif_dev->tx.tx_skb_queue, skb, tmp) {
if ( F_46 ( V_12 , V_67 ) ) {
F_49 ( V_12 , & V_10 -> V_24 . V_50 ) ;
F_2 ( V_10 -> V_11 ,
V_12 , false ) ;
V_10 -> V_24 . V_46 -- ;
F_25 ( V_37 ) ;
}
}
F_37 ( & V_10 -> V_24 . V_25 , V_26 ) ;
}
static void F_50 ( struct V_13 * V_10 ,
struct V_14 * V_12 )
{
struct V_14 * V_44 , * V_70 [ V_71 ] ;
int V_72 = 0 , V_45 = 0 , V_21 = V_12 -> V_21 ;
int V_73 , V_74 ;
T_2 V_75 = 0 ;
T_3 * V_76 ;
F_15 ( & V_10 -> V_77 ) ;
V_73 = V_10 -> V_73 ;
V_74 = V_10 -> V_78 ;
if ( V_73 != 0 ) {
struct V_14 * V_79 = V_10 -> V_79 ;
if ( V_79 ) {
V_76 = ( T_3 * ) V_79 -> V_20 ;
V_72 = V_73 ;
V_73 -= V_10 -> V_80 ;
V_76 += V_74 ;
memcpy ( V_76 , V_12 -> V_20 , V_73 ) ;
V_74 += V_73 ;
V_10 -> V_73 = 0 ;
F_51 ( V_79 , V_74 ) ;
V_70 [ V_75 ++ ] = V_79 ;
} else {
V_72 = V_73 ;
}
}
F_16 ( & V_10 -> V_77 ) ;
while ( V_72 < V_21 ) {
T_2 V_81 ;
T_2 V_82 ;
T_2 V_83 ;
int V_84 ;
V_76 = ( T_3 * ) V_12 -> V_20 ;
V_81 = F_52 ( V_76 + V_72 ) ;
V_82 = F_52 ( V_76 + V_72 + 2 ) ;
if ( V_82 != V_85 ) {
F_53 ( V_86 ) ;
return;
}
V_83 = 4 - ( V_81 & 0x3 ) ;
if ( V_83 == 4 )
V_83 = 0 ;
V_84 = V_72 ;
V_72 = V_72 + 4 + V_81 + V_83 ;
if ( V_72 > V_87 ) {
F_15 ( & V_10 -> V_77 ) ;
V_10 -> V_73 = V_72 - V_87 ;
V_10 -> V_78 =
V_87 - V_84 - 4 ;
V_10 -> V_80 = V_83 ;
V_44 = F_54 ( V_81 + 32 , V_29 ) ;
if ( ! V_44 ) {
F_45 ( & V_10 -> V_18 -> V_65 ,
L_2 ) ;
F_16 ( & V_10 -> V_77 ) ;
goto V_88;
}
F_55 ( V_44 , 32 ) ;
F_53 ( V_89 ) ;
memcpy ( V_44 -> V_20 , & ( V_12 -> V_20 [ V_84 + 4 ] ) ,
V_10 -> V_78 ) ;
V_10 -> V_79 = V_44 ;
F_16 ( & V_10 -> V_77 ) ;
} else {
V_44 = F_54 ( V_81 + 32 , V_29 ) ;
if ( ! V_44 ) {
F_45 ( & V_10 -> V_18 -> V_65 ,
L_2 ) ;
goto V_88;
}
F_55 ( V_44 , 32 ) ;
F_53 ( V_89 ) ;
memcpy ( V_44 -> V_20 , & ( V_12 -> V_20 [ V_84 + 4 ] ) , V_81 ) ;
F_51 ( V_44 , V_81 ) ;
V_70 [ V_75 ++ ] = V_44 ;
}
}
V_88:
for ( V_45 = 0 ; V_45 < V_75 ; V_45 ++ ) {
F_56 ( V_10 -> V_11 , V_70 [ V_45 ] ,
V_70 [ V_45 ] -> V_21 , V_90 ) ;
F_53 ( V_91 ) ;
}
}
static void F_57 ( struct V_1 * V_1 )
{
struct V_14 * V_12 = (struct V_14 * ) V_1 -> V_4 ;
struct V_13 * V_10 =
F_58 ( F_59 ( V_1 -> V_65 , 0 ) ) ;
int V_15 ;
if ( ! V_12 )
return;
if ( ! V_10 )
goto free;
switch ( V_1 -> V_5 ) {
case 0 :
break;
case - V_6 :
case - V_7 :
case - V_8 :
case - V_9 :
goto free;
default:
goto V_92;
}
if ( F_60 ( V_1 -> V_93 != 0 ) ) {
F_51 ( V_12 , V_1 -> V_93 ) ;
F_50 ( V_10 , V_12 ) ;
}
V_92:
F_61 ( V_12 ) ;
F_62 ( V_12 , 0 ) ;
F_11 ( V_1 , & V_10 -> V_94 ) ;
V_15 = F_12 ( V_1 , V_29 ) ;
if ( V_15 ) {
F_13 ( V_1 ) ;
goto free;
}
return;
free:
F_4 ( V_12 ) ;
}
static void F_63 ( struct V_1 * V_1 )
{
struct V_14 * V_12 = (struct V_14 * ) V_1 -> V_4 ;
struct V_14 * V_44 ;
struct V_13 * V_10 =
F_58 ( F_59 ( V_1 -> V_65 , 0 ) ) ;
int V_15 ;
if ( ! V_12 )
return;
if ( ! V_10 )
goto free;
switch ( V_1 -> V_5 ) {
case 0 :
break;
case - V_6 :
case - V_7 :
case - V_8 :
case - V_9 :
goto free;
default:
F_61 ( V_12 ) ;
F_62 ( V_12 , 0 ) ;
goto V_92;
}
if ( F_60 ( V_1 -> V_93 != 0 ) ) {
F_51 ( V_12 , V_1 -> V_93 ) ;
F_56 ( V_10 -> V_11 , V_12 ,
V_12 -> V_21 , V_95 ) ;
V_44 = F_64 ( V_96 , V_29 ) ;
if ( ! V_44 ) {
F_45 ( & V_10 -> V_18 -> V_65 ,
L_3 ) ;
V_1 -> V_4 = NULL ;
return;
}
F_9 ( V_1 , V_10 -> V_18 ,
F_65 ( V_10 -> V_18 ,
V_95 ) ,
V_44 -> V_20 , V_96 ,
F_63 , V_44 ) ;
}
V_92:
F_11 ( V_1 , & V_10 -> V_97 ) ;
V_15 = F_12 ( V_1 , V_29 ) ;
if ( V_15 ) {
F_13 ( V_1 ) ;
goto free;
}
return;
free:
F_4 ( V_12 ) ;
V_1 -> V_4 = NULL ;
}
static void F_66 ( struct V_13 * V_10 )
{
struct V_38 * V_38 = NULL , * V_63 = NULL ;
unsigned long V_26 ;
F_41 (tx_buf, tx_buf_tmp,
&hif_dev->tx.tx_buf, list) {
F_42 ( V_38 -> V_1 ) ;
F_67 ( & V_38 -> V_34 ) ;
F_8 ( V_38 -> V_1 ) ;
F_3 ( V_38 -> V_47 ) ;
F_3 ( V_38 ) ;
}
F_36 ( & V_10 -> V_24 . V_25 , V_26 ) ;
V_10 -> V_24 . V_26 |= V_27 ;
F_37 ( & V_10 -> V_24 . V_25 , V_26 ) ;
F_41 (tx_buf, tx_buf_tmp,
&hif_dev->tx.tx_pending, list) {
F_42 ( V_38 -> V_1 ) ;
F_67 ( & V_38 -> V_34 ) ;
F_8 ( V_38 -> V_1 ) ;
F_3 ( V_38 -> V_47 ) ;
F_3 ( V_38 ) ;
}
F_43 ( & V_10 -> V_32 ) ;
}
static int F_68 ( struct V_13 * V_10 )
{
struct V_38 * V_38 ;
int V_45 ;
F_69 ( & V_10 -> V_24 . V_38 ) ;
F_69 ( & V_10 -> V_24 . V_48 ) ;
F_70 ( & V_10 -> V_24 . V_25 ) ;
F_27 ( & V_10 -> V_24 . V_50 ) ;
F_71 ( & V_10 -> V_32 ) ;
for ( V_45 = 0 ; V_45 < V_60 ; V_45 ++ ) {
V_38 = F_7 ( sizeof( struct V_38 ) , V_16 ) ;
if ( ! V_38 )
goto V_88;
V_38 -> V_47 = F_7 ( V_98 , V_16 ) ;
if ( ! V_38 -> V_47 )
goto V_88;
V_38 -> V_1 = F_6 ( 0 , V_16 ) ;
if ( ! V_38 -> V_1 )
goto V_88;
V_38 -> V_10 = V_10 ;
F_27 ( & V_38 -> V_39 ) ;
F_72 ( & V_38 -> V_34 , & V_10 -> V_24 . V_38 ) ;
}
V_10 -> V_24 . V_41 = V_60 ;
return 0 ;
V_88:
if ( V_38 ) {
F_3 ( V_38 -> V_47 ) ;
F_3 ( V_38 ) ;
}
F_66 ( V_10 ) ;
return - V_17 ;
}
static void F_73 ( struct V_13 * V_10 )
{
F_43 ( & V_10 -> V_94 ) ;
}
static int F_74 ( struct V_13 * V_10 )
{
struct V_1 * V_1 = NULL ;
struct V_14 * V_12 = NULL ;
int V_45 , V_15 ;
F_71 ( & V_10 -> V_94 ) ;
F_70 ( & V_10 -> V_77 ) ;
for ( V_45 = 0 ; V_45 < V_99 ; V_45 ++ ) {
V_1 = F_6 ( 0 , V_16 ) ;
if ( V_1 == NULL ) {
V_15 = - V_17 ;
goto V_100;
}
V_12 = F_64 ( V_87 , V_16 ) ;
if ( ! V_12 ) {
V_15 = - V_17 ;
goto V_101;
}
F_9 ( V_1 , V_10 -> V_18 ,
F_65 ( V_10 -> V_18 ,
V_90 ) ,
V_12 -> V_20 , V_87 ,
F_57 , V_12 ) ;
F_11 ( V_1 , & V_10 -> V_94 ) ;
V_15 = F_12 ( V_1 , V_16 ) ;
if ( V_15 ) {
F_13 ( V_1 ) ;
goto V_102;
}
F_8 ( V_1 ) ;
}
return 0 ;
V_102:
F_4 ( V_12 ) ;
V_101:
F_8 ( V_1 ) ;
V_100:
F_73 ( V_10 ) ;
return V_15 ;
}
static void F_75 ( struct V_13 * V_10 )
{
F_43 ( & V_10 -> V_97 ) ;
}
static int F_76 ( struct V_13 * V_10 )
{
struct V_1 * V_1 = NULL ;
struct V_14 * V_12 = NULL ;
int V_45 , V_15 ;
F_71 ( & V_10 -> V_97 ) ;
for ( V_45 = 0 ; V_45 < V_103 ; V_45 ++ ) {
V_1 = F_6 ( 0 , V_16 ) ;
if ( V_1 == NULL ) {
V_15 = - V_17 ;
goto V_100;
}
V_12 = F_64 ( V_96 , V_16 ) ;
if ( ! V_12 ) {
V_15 = - V_17 ;
goto V_101;
}
F_9 ( V_1 , V_10 -> V_18 ,
F_65 ( V_10 -> V_18 ,
V_95 ) ,
V_12 -> V_20 , V_96 ,
F_63 , V_12 ) ;
F_11 ( V_1 , & V_10 -> V_97 ) ;
V_15 = F_12 ( V_1 , V_16 ) ;
if ( V_15 ) {
F_13 ( V_1 ) ;
goto V_102;
}
F_8 ( V_1 ) ;
}
return 0 ;
V_102:
F_4 ( V_12 ) ;
V_101:
F_8 ( V_1 ) ;
V_100:
F_75 ( V_10 ) ;
return V_15 ;
}
static int F_77 ( struct V_13 * V_10 )
{
F_71 ( & V_10 -> V_22 ) ;
if ( F_68 ( V_10 ) < 0 )
goto V_88;
if ( F_74 ( V_10 ) < 0 )
goto V_104;
if ( F_76 ( V_10 ) < 0 )
goto V_105;
return 0 ;
V_105:
F_73 ( V_10 ) ;
V_104:
F_66 ( V_10 ) ;
V_88:
return - V_17 ;
}
static void F_78 ( struct V_13 * V_10 )
{
F_43 ( & V_10 -> V_22 ) ;
F_75 ( V_10 ) ;
F_66 ( V_10 ) ;
F_73 ( V_10 ) ;
}
static int F_79 ( struct V_13 * V_10 )
{
int V_106 , V_88 ;
const void * V_20 = V_10 -> V_107 ;
T_4 V_21 = V_10 -> V_108 ;
T_5 V_109 = V_110 ;
T_3 * V_47 = F_7 ( 4096 , V_16 ) ;
T_5 V_111 ;
if ( ! V_47 )
return - V_17 ;
while ( V_21 ) {
V_106 = F_32 ( T_4 , V_21 , 4096 ) ;
memcpy ( V_47 , V_20 , V_106 ) ;
V_88 = F_80 ( V_10 -> V_18 ,
F_81 ( V_10 -> V_18 , 0 ) ,
V_112 , 0x40 | V_113 ,
V_109 >> 8 , 0 , V_47 , V_106 , V_114 ) ;
if ( V_88 < 0 ) {
F_3 ( V_47 ) ;
return V_88 ;
}
V_21 -= V_106 ;
V_20 += V_106 ;
V_109 += V_106 ;
}
F_3 ( V_47 ) ;
if ( F_82 ( V_10 -> V_115 -> V_116 ) )
V_111 = V_117 ;
else
V_111 = V_118 ;
V_88 = F_80 ( V_10 -> V_18 , F_81 ( V_10 -> V_18 , 0 ) ,
V_119 ,
0x40 | V_113 ,
V_111 >> 8 , 0 , NULL , 0 , V_114 ) ;
if ( V_88 )
return - V_120 ;
F_83 ( & V_10 -> V_18 -> V_65 , L_4 ,
V_10 -> V_121 , ( unsigned long ) V_10 -> V_108 ) ;
return 0 ;
}
static int F_84 ( struct V_13 * V_10 )
{
struct V_122 * V_123 = & V_10 -> V_124 -> V_125 [ 0 ] ;
struct V_126 * V_127 ;
int V_15 , V_67 ;
V_15 = F_79 ( V_10 ) ;
if ( V_15 ) {
F_45 ( & V_10 -> V_18 -> V_65 ,
L_5 ,
V_10 -> V_121 ) ;
return V_15 ;
}
for ( V_67 = 0 ; V_67 < V_123 -> V_128 . V_129 ; V_67 ++ ) {
V_127 = & V_123 -> V_130 [ V_67 ] . V_128 ;
if ( ( V_127 -> V_131 & V_132 )
== V_133 ) {
V_127 -> V_131 &= ~ V_132 ;
V_127 -> V_131 |= V_134 ;
V_127 -> V_135 = 0 ;
}
}
V_15 = F_77 ( V_10 ) ;
if ( V_15 ) {
F_45 ( & V_10 -> V_18 -> V_65 ,
L_6 ) ;
return V_15 ;
}
return 0 ;
}
static void F_85 ( struct V_13 * V_10 )
{
F_78 ( V_10 ) ;
}
static void F_86 ( struct V_13 * V_10 )
{
struct V_136 * V_65 = & V_10 -> V_18 -> V_65 ;
struct V_136 * V_137 = V_65 -> V_137 ;
F_87 ( & V_10 -> V_138 ) ;
if ( V_137 )
F_88 ( V_137 ) ;
F_89 ( V_65 ) ;
if ( V_137 )
F_90 ( V_137 ) ;
}
static void F_91 ( const struct V_139 * V_140 , void * V_4 )
{
struct V_13 * V_10 = V_4 ;
int V_15 ;
if ( ! V_140 ) {
F_45 ( & V_10 -> V_18 -> V_65 ,
L_7 ,
V_10 -> V_121 ) ;
goto V_141;
}
V_10 -> V_11 = F_92 ( V_10 , & V_142 ,
& V_10 -> V_18 -> V_65 ) ;
if ( V_10 -> V_11 == NULL )
goto V_143;
V_10 -> V_107 = V_140 -> V_20 ;
V_10 -> V_108 = V_140 -> V_144 ;
V_15 = F_84 ( V_10 ) ;
if ( V_15 )
goto V_145;
V_15 = F_93 ( V_10 -> V_11 ,
& V_10 -> V_124 -> V_65 ,
V_10 -> V_115 -> V_146 ,
V_10 -> V_18 -> V_147 ,
V_10 -> V_115 -> V_116 ) ;
if ( V_15 ) {
V_15 = - V_66 ;
goto V_148;
}
F_94 ( V_140 ) ;
V_10 -> V_26 |= V_149 ;
F_87 ( & V_10 -> V_138 ) ;
return;
V_148:
F_85 ( V_10 ) ;
V_145:
F_95 ( V_10 -> V_11 ) ;
V_143:
F_94 ( V_140 ) ;
V_141:
F_86 ( V_10 ) ;
}
static int F_96 ( struct V_150 * V_124 )
{
struct V_151 * V_18 = F_97 ( V_124 ) ;
struct V_122 * V_152 = & V_124 -> V_125 [ 0 ] ;
struct V_126 * V_130 ;
unsigned char * V_3 ;
T_3 V_153 ;
int V_154 ;
for ( V_154 = 1 ; V_154 >= 0 ; V_154 -- ) {
V_130 = & V_152 -> V_130 [ V_154 ] . V_128 ;
if ( F_98 ( V_130 ) &&
F_99 ( V_130 ) ) {
V_153 = V_130 -> V_155 ;
break;
}
}
if ( V_154 == - 1 ) {
F_45 ( & V_18 -> V_65 ,
L_8 ) ;
return - V_8 ;
}
V_3 = F_7 ( 31 , V_16 ) ;
if ( V_3 == NULL )
return - V_8 ;
V_3 [ 0 ] = 0x55 ;
V_3 [ 1 ] = 0x53 ;
V_3 [ 2 ] = 0x42 ;
V_3 [ 3 ] = 0x43 ;
V_3 [ 14 ] = 6 ;
V_3 [ 15 ] = 0x1b ;
V_3 [ 19 ] = 0x2 ;
F_83 ( & V_18 -> V_65 , L_9 ) ;
V_154 = F_100 ( V_18 , F_10 ( V_18 , V_153 ) ,
V_3 , 31 , NULL , 2000 ) ;
F_3 ( V_3 ) ;
if ( V_154 )
return V_154 ;
F_101 ( V_124 , NULL ) ;
return 0 ;
}
static int F_102 ( struct V_150 * V_124 ,
const struct V_115 * V_156 )
{
struct V_151 * V_18 = F_97 ( V_124 ) ;
struct V_13 * V_10 ;
int V_15 = 0 ;
if ( V_156 -> V_116 == V_157 )
return F_96 ( V_124 ) ;
V_10 = F_7 ( sizeof( struct V_13 ) , V_16 ) ;
if ( ! V_10 ) {
V_15 = - V_17 ;
goto V_158;
}
F_103 ( V_18 ) ;
V_10 -> V_18 = V_18 ;
V_10 -> V_124 = V_124 ;
V_10 -> V_115 = V_156 ;
#ifdef F_104
V_18 -> V_159 = 1 ;
#endif
F_101 ( V_124 , V_10 ) ;
F_105 ( & V_10 -> V_138 ) ;
if ( F_82 ( V_156 -> V_116 ) )
V_10 -> V_121 = V_160 ;
else
V_10 -> V_121 = V_161 ;
V_15 = F_106 ( V_162 , true , V_10 -> V_121 ,
& V_10 -> V_18 -> V_65 , V_16 ,
V_10 , F_91 ) ;
if ( V_15 ) {
F_45 ( & V_10 -> V_18 -> V_65 ,
L_10 ,
V_10 -> V_121 ) ;
goto V_163;
}
F_83 ( & V_10 -> V_18 -> V_65 , L_11 ,
V_10 -> V_121 ) ;
return 0 ;
V_163:
F_101 ( V_124 , NULL ) ;
F_3 ( V_10 ) ;
F_107 ( V_18 ) ;
V_158:
return V_15 ;
}
static void F_108 ( struct V_151 * V_18 )
{
T_5 V_164 = 0xffffffff ;
void * V_47 ;
int V_15 ;
V_47 = F_109 ( & V_164 , 4 , V_16 ) ;
if ( ! V_47 )
return;
V_15 = F_100 ( V_18 , F_10 ( V_18 , V_19 ) ,
V_47 , 4 , NULL , V_114 ) ;
if ( V_15 )
F_45 ( & V_18 -> V_65 , L_12 ) ;
F_3 ( V_47 ) ;
}
static void F_110 ( struct V_150 * V_124 )
{
struct V_151 * V_18 = F_97 ( V_124 ) ;
struct V_13 * V_10 = F_58 ( V_124 ) ;
bool V_165 = ( V_18 -> V_166 == V_167 ) ? true : false ;
if ( ! V_10 )
return;
F_111 ( & V_10 -> V_138 ) ;
if ( V_10 -> V_26 & V_149 ) {
F_112 ( V_10 -> V_11 , V_165 ) ;
F_95 ( V_10 -> V_11 ) ;
F_85 ( V_10 ) ;
}
F_101 ( V_124 , NULL ) ;
if ( ! V_165 && ( V_10 -> V_26 & V_62 ) )
F_108 ( V_18 ) ;
F_3 ( V_10 ) ;
F_83 ( & V_18 -> V_65 , L_13 ) ;
F_107 ( V_18 ) ;
}
static int F_113 ( struct V_150 * V_124 ,
T_6 V_168 )
{
struct V_13 * V_10 = F_58 ( V_124 ) ;
if ( ! ( V_10 -> V_26 & V_62 ) )
F_114 ( V_10 -> V_11 ) ;
F_78 ( V_10 ) ;
return 0 ;
}
static int F_115 ( struct V_150 * V_124 )
{
struct V_13 * V_10 = F_58 ( V_124 ) ;
struct V_169 * V_11 = V_10 -> V_11 ;
int V_15 ;
const struct V_139 * V_140 ;
V_15 = F_77 ( V_10 ) ;
if ( V_15 )
return V_15 ;
if ( V_10 -> V_26 & V_149 ) {
V_15 = F_116 ( & V_140 , V_10 -> V_121 ,
& V_10 -> V_18 -> V_65 ) ;
if ( V_15 )
goto V_170;
V_10 -> V_107 = V_140 -> V_20 ;
V_10 -> V_108 = V_140 -> V_144 ;
V_15 = F_79 ( V_10 ) ;
F_94 ( V_140 ) ;
if ( V_15 )
goto V_170;
} else {
F_78 ( V_10 ) ;
return - V_120 ;
}
F_117 ( 100 ) ;
V_15 = F_118 ( V_11 ) ;
if ( V_15 )
goto V_170;
return 0 ;
V_170:
F_78 ( V_10 ) ;
return V_15 ;
}
int F_119 ( void )
{
return F_120 ( & V_171 ) ;
}
void F_121 ( void )
{
F_122 ( & V_171 ) ;
}
