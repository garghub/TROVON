static T_1
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_10 ;
T_1 V_11 = 0 ;
int V_12 ;
F_2 ( V_5 , L_1 , V_2 -> V_13 , V_3 ) ;
for ( V_12 = 32 ; V_12 > 0 ; V_12 -= V_10 -> V_14 ) {
V_11 ^= ( V_3 & ( ( 1 << V_10 -> V_14 ) - 1 ) ) ;
V_3 >>= V_10 -> V_14 ;
}
if ( V_7 -> V_15 < V_16 )
V_11 ^= V_2 -> V_13 << ( V_10 -> V_14 - 4 ) ;
V_11 <<= 3 ;
F_2 ( V_5 , L_2 , V_11 ) ;
return V_11 ;
}
static int
F_3 ( struct V_4 * V_5 , struct V_17 * V_10 ,
T_1 V_18 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_19 = F_4 ( V_10 , V_18 + 4 ) ;
if ( V_7 -> V_15 < V_20 )
return ( ( V_19 & V_21 ) != 0 ) ;
return ( V_19 != 0 ) ;
}
static int
F_5 ( struct V_1 * V_2 ,
struct V_17 * V_10 , T_1 V_18 )
{
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
T_1 V_19 = F_4 ( V_10 , V_18 + 4 ) ;
if ( V_7 -> V_15 >= V_16 )
return true ;
else if ( V_7 -> V_15 >= V_20 )
return V_2 -> V_13 ==
( ( V_19 >> V_22 ) & 0x1f ) ;
else
return V_2 -> V_13 ==
( ( V_19 >> V_23 ) & 0x1f ) ;
}
int
F_6 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_17 * V_24 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_25 * V_26 = & V_7 -> V_27 . V_26 ;
struct V_28 * V_29 ;
struct V_17 * V_10 = V_2 -> V_10 -> V_24 ;
unsigned long V_30 ;
T_1 V_19 , V_31 , V_32 ;
if ( F_7 ( V_2 , V_3 ) )
return - V_33 ;
V_29 = F_8 ( sizeof( * V_29 ) , V_34 ) ;
if ( ! V_29 )
return - V_35 ;
V_29 -> V_36 = V_2 ;
V_29 -> V_24 = NULL ;
V_29 -> V_3 = V_3 ;
F_9 ( V_24 , & V_29 -> V_24 ) ;
if ( V_7 -> V_15 < V_20 ) {
V_19 = V_21 | ( V_24 -> V_37 >> 4 ) |
( V_2 -> V_13 << V_23 ) |
( V_24 -> V_27 << V_38 ) ;
} else
if ( V_7 -> V_15 < V_16 ) {
V_19 = ( V_24 -> V_37 >> 4 ) |
( V_2 -> V_13 << V_22 ) |
( V_24 -> V_27 << V_39 ) ;
} else {
if ( V_24 -> V_27 == V_40 ) {
V_19 = ( V_24 -> V_41 << 10 ) |
( V_2 -> V_13 << 28 ) |
V_2 -> V_13 ;
} else {
V_19 = ( V_24 -> V_41 >> 4 ) |
( ( V_24 -> V_27 <<
V_39 ) ) ;
}
}
F_10 ( & V_2 -> V_10 -> V_42 , V_30 ) ;
F_11 ( & V_29 -> V_43 , & V_2 -> V_10 -> V_44 ) ;
V_31 = V_32 = F_1 ( V_2 , V_3 ) ;
do {
if ( ! F_3 ( V_5 , V_10 , V_31 ) ) {
F_2 ( V_5 ,
L_3 ,
V_2 -> V_13 , V_31 , V_3 , V_19 ) ;
F_12 ( V_10 , V_31 + 0 , V_3 ) ;
F_12 ( V_10 , V_31 + 4 , V_19 ) ;
F_13 ( & V_2 -> V_10 -> V_42 , V_30 ) ;
V_26 -> V_45 ( V_5 ) ;
return 0 ;
}
F_2 ( V_5 , L_4 ,
V_2 -> V_13 , V_31 , F_4 ( V_10 , V_31 ) ) ;
V_31 += 8 ;
if ( V_31 >= V_10 -> V_46 )
V_31 = 0 ;
} while ( V_31 != V_32 );
F_14 ( V_5 , L_5 , V_2 -> V_13 ) ;
F_15 ( & V_29 -> V_43 ) ;
F_13 ( & V_2 -> V_10 -> V_42 , V_30 ) ;
F_16 ( V_29 ) ;
return - V_35 ;
}
static struct V_28 *
F_17 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_9 * V_10 = V_2 ? V_2 -> V_10 : NULL ;
struct V_28 * V_29 ;
unsigned long V_30 ;
if ( ! V_10 )
return NULL ;
F_10 ( & V_10 -> V_42 , V_30 ) ;
F_18 (entry, &ramht->entries, head) {
if ( V_29 -> V_36 == V_2 &&
( ! V_3 || V_29 -> V_3 == V_3 ) ) {
F_15 ( & V_29 -> V_43 ) ;
F_13 ( & V_10 -> V_42 , V_30 ) ;
return V_29 ;
}
}
F_13 ( & V_10 -> V_42 , V_30 ) ;
return NULL ;
}
static void
F_19 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_25 * V_26 = & V_7 -> V_27 . V_26 ;
struct V_17 * V_10 = V_2 -> V_10 -> V_24 ;
unsigned long V_30 ;
T_1 V_31 , V_32 ;
F_10 ( & V_2 -> V_10 -> V_42 , V_30 ) ;
V_31 = V_32 = F_1 ( V_2 , V_3 ) ;
do {
if ( F_3 ( V_5 , V_10 , V_31 ) &&
F_5 ( V_2 , V_10 , V_31 ) &&
( V_3 == F_4 ( V_10 , V_31 ) ) ) {
F_2 ( V_5 ,
L_6 ,
V_2 -> V_13 , V_31 , V_3 , F_4 ( V_10 , V_31 + 4 ) ) ;
F_12 ( V_10 , V_31 + 0 , 0x00000000 ) ;
F_12 ( V_10 , V_31 + 4 , 0x00000000 ) ;
V_26 -> V_45 ( V_5 ) ;
goto V_47;
}
V_31 += 8 ;
if ( V_31 >= V_10 -> V_46 )
V_31 = 0 ;
} while ( V_31 != V_32 );
F_14 ( V_5 , L_7 ,
V_2 -> V_13 , V_3 ) ;
V_47:
F_13 ( & V_2 -> V_10 -> V_42 , V_30 ) ;
}
int
F_20 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_28 * V_29 ;
V_29 = F_17 ( V_2 , V_3 ) ;
if ( ! V_29 )
return - V_48 ;
F_19 ( V_2 , V_29 -> V_3 ) ;
F_9 ( NULL , & V_29 -> V_24 ) ;
F_16 ( V_29 ) ;
return 0 ;
}
struct V_17 *
F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_28 * V_29 ;
struct V_17 * V_24 = NULL ;
unsigned long V_30 ;
if ( F_21 ( ! V_2 -> V_10 ) )
return NULL ;
F_10 ( & V_10 -> V_42 , V_30 ) ;
F_18 (entry, &chan->ramht->entries, head) {
if ( V_29 -> V_36 == V_2 && V_29 -> V_3 == V_3 ) {
V_24 = V_29 -> V_24 ;
break;
}
}
F_13 ( & V_10 -> V_42 , V_30 ) ;
return V_24 ;
}
int
F_22 ( struct V_4 * V_5 , struct V_17 * V_24 ,
struct V_9 * * V_49 )
{
struct V_9 * V_10 ;
V_10 = F_23 ( sizeof( * V_10 ) , V_34 ) ;
if ( ! V_10 )
return - V_35 ;
V_10 -> V_5 = V_5 ;
F_24 ( & V_10 -> V_50 ) ;
V_10 -> V_14 = F_25 ( V_24 -> V_46 / 8 ) ;
F_26 ( & V_10 -> V_44 ) ;
F_27 ( & V_10 -> V_42 ) ;
F_9 ( V_24 , & V_10 -> V_24 ) ;
* V_49 = V_10 ;
return 0 ;
}
static void
F_28 ( struct V_51 * V_52 )
{
struct V_9 * V_10 =
F_29 ( V_52 , struct V_9 , V_50 ) ;
F_9 ( NULL , & V_10 -> V_24 ) ;
F_16 ( V_10 ) ;
}
void
F_30 ( struct V_9 * V_52 , struct V_9 * * V_53 ,
struct V_1 * V_2 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
if ( V_52 )
F_31 ( & V_52 -> V_50 ) ;
V_10 = * V_53 ;
if ( V_10 ) {
while ( ( V_29 = F_17 ( V_2 , 0 ) ) ) {
F_19 ( V_2 , V_29 -> V_3 ) ;
F_9 ( NULL , & V_29 -> V_24 ) ;
F_16 ( V_29 ) ;
}
F_32 ( & V_10 -> V_50 , F_28 ) ;
}
* V_53 = V_52 ;
}
