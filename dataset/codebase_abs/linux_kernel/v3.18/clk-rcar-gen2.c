static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
unsigned int V_7 ;
V_7 = ( F_3 ( V_5 -> V_8 ) & V_9 )
>> V_10 ;
V_6 = 32 - V_7 ;
return F_4 ( ( V_11 ) V_3 * V_6 , 32 ) ;
}
static long F_5 ( struct V_1 * V_2 , unsigned long V_12 ,
unsigned long * V_3 )
{
unsigned long V_13 = * V_3 ;
unsigned int V_6 ;
if ( ! V_13 )
V_13 = 1 ;
V_6 = F_4 ( ( V_11 ) V_12 * 32 , V_13 ) ;
V_6 = F_6 ( V_6 , 1U , 32U ) ;
return * V_3 / 32 * V_6 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned long V_12 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
T_1 V_7 , V_14 ;
unsigned int V_15 ;
V_6 = F_4 ( ( V_11 ) V_12 * 32 , V_3 ) ;
V_6 = F_6 ( V_6 , 1U , 32U ) ;
if ( F_3 ( V_5 -> V_16 ) & V_17 )
return - V_18 ;
V_7 = F_3 ( V_5 -> V_8 ) ;
V_7 &= ~ V_9 ;
V_7 |= ( 32 - V_6 ) << V_10 ;
F_8 ( V_7 , V_5 -> V_8 ) ;
V_14 = F_3 ( V_5 -> V_16 ) ;
V_14 |= V_17 ;
F_8 ( V_14 , V_5 -> V_16 ) ;
for ( V_15 = 1000 ; V_15 ; V_15 -- ) {
if ( ! ( F_3 ( V_5 -> V_16 ) & V_17 ) )
return 0 ;
F_9 () ;
}
return - V_19 ;
}
static struct V_20 * T_2 F_10 ( struct V_21 * V_22 )
{
static const char * V_23 = L_1 ;
struct V_24 V_25 ;
struct V_4 * V_5 ;
struct V_20 * V_20 ;
V_5 = F_11 ( sizeof( * V_5 ) , V_26 ) ;
if ( ! V_5 )
return F_12 ( - V_27 ) ;
V_25 . V_28 = L_2 ;
V_25 . V_29 = & V_30 ;
V_25 . V_31 = 0 ;
V_25 . V_32 = & V_23 ;
V_25 . V_33 = 1 ;
V_5 -> V_8 = V_22 -> V_8 + V_34 ;
V_5 -> V_16 = V_22 -> V_8 + V_35 ;
V_5 -> V_2 . V_25 = & V_25 ;
V_20 = F_13 ( NULL , & V_5 -> V_2 ) ;
if ( F_14 ( V_20 ) )
F_15 ( V_5 ) ;
return V_20 ;
}
static struct V_20 * T_2
F_16 ( struct V_36 * V_37 , struct V_21 * V_22 ,
const struct V_38 * V_39 ,
const char * V_28 )
{
const struct V_40 * V_41 = NULL ;
const char * V_23 ;
unsigned int V_42 ;
unsigned int V_6 = 1 ;
unsigned int div = 1 ;
if ( ! strcmp ( V_28 , L_3 ) ) {
V_23 = F_17 ( V_37 , 0 ) ;
div = V_39 -> V_43 ;
} else if ( ! strcmp ( V_28 , L_1 ) ) {
T_1 V_44 = F_3 ( V_22 -> V_8 + V_45 ) ;
V_23 = L_3 ;
V_6 = ( ( V_44 >> 24 ) & ( ( 1 << 7 ) - 1 ) ) + 1 ;
} else if ( ! strcmp ( V_28 , L_4 ) ) {
V_23 = L_3 ;
V_6 = V_39 -> V_46 / 2 ;
} else if ( ! strcmp ( V_28 , L_5 ) ) {
V_23 = L_3 ;
V_6 = V_39 -> V_47 ;
} else if ( ! strcmp ( V_28 , L_6 ) ) {
V_23 = L_4 ;
div = V_48 & F_18 ( 18 ) ? 36 : 24 ;
} else if ( ! strcmp ( V_28 , L_7 ) ) {
V_23 = L_8 ;
div = ( V_48 & ( F_18 ( 3 ) | F_18 ( 2 ) | F_18 ( 1 ) ) ) == F_18 ( 2 )
? 8 : 10 ;
} else if ( ! strcmp ( V_28 , L_9 ) ) {
V_23 = L_4 ;
V_41 = V_49 ;
V_42 = 8 ;
} else if ( ! strcmp ( V_28 , L_10 ) ) {
V_23 = L_4 ;
V_41 = V_50 ;
V_42 = 4 ;
} else if ( ! strcmp ( V_28 , L_11 ) ) {
V_23 = L_4 ;
V_41 = V_50 ;
V_42 = 0 ;
} else if ( ! strcmp ( V_28 , L_2 ) ) {
return F_10 ( V_22 ) ;
} else {
return F_12 ( - V_51 ) ;
}
if ( ! V_41 )
return F_19 ( NULL , V_28 , V_23 , 0 ,
V_6 , div ) ;
else
return F_20 ( NULL , V_28 , V_23 , 0 ,
V_22 -> V_8 + V_52 , V_42 ,
4 , 0 , V_41 , & V_22 -> V_53 ) ;
}
static void T_2 F_21 ( struct V_36 * V_37 )
{
const struct V_38 * V_39 ;
struct V_21 * V_22 ;
struct V_20 * * V_54 ;
unsigned int V_15 ;
int V_55 ;
V_55 = F_22 ( V_37 , L_12 ) ;
if ( V_55 < 0 ) {
F_23 ( L_13 , V_56 ) ;
return;
}
V_22 = F_11 ( sizeof( * V_22 ) , V_26 ) ;
V_54 = F_11 ( V_55 * sizeof( * V_54 ) , V_26 ) ;
if ( V_22 == NULL || V_54 == NULL ) {
F_23 ( L_14 , V_56 ) ;
return;
}
F_24 ( & V_22 -> V_53 ) ;
V_22 -> V_57 . V_54 = V_54 ;
V_22 -> V_57 . V_58 = V_55 ;
V_22 -> V_8 = F_25 ( V_37 , 0 ) ;
if ( F_26 ( V_22 -> V_8 == NULL ) )
return;
V_39 = & V_59 [ F_27 ( V_48 ) ] ;
for ( V_15 = 0 ; V_15 < V_55 ; ++ V_15 ) {
const char * V_28 ;
struct V_20 * V_20 ;
F_28 ( V_37 , L_12 , V_15 ,
& V_28 ) ;
V_20 = F_16 ( V_37 , V_22 , V_39 , V_28 ) ;
if ( F_14 ( V_20 ) )
F_23 ( L_15 ,
V_56 , V_37 -> V_28 , V_28 , F_29 ( V_20 ) ) ;
else
V_22 -> V_57 . V_54 [ V_15 ] = V_20 ;
}
F_30 ( V_37 , V_60 , & V_22 -> V_57 ) ;
}
void T_2 F_31 ( T_1 V_61 )
{
V_48 = V_61 ;
F_32 ( NULL ) ;
}
