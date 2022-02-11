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
static struct V_20 * T_2 F_16 ( struct V_21 * V_22 ,
struct V_36 * V_37 )
{
const char * V_23 = F_17 ( V_37 , 1 ) ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
struct V_20 * V_20 ;
V_39 = F_11 ( sizeof( * V_39 ) , V_26 ) ;
if ( ! V_39 )
return F_12 ( - V_27 ) ;
V_39 -> V_6 = 1 ;
V_39 -> div = 6 ;
V_41 = F_11 ( sizeof( * V_41 ) , V_26 ) ;
if ( ! V_41 ) {
F_15 ( V_39 ) ;
return F_12 ( - V_27 ) ;
}
V_41 -> V_8 = V_22 -> V_8 + V_42 ;
V_41 -> V_43 = 8 ;
V_41 -> V_31 = V_44 ;
V_41 -> V_45 = & V_22 -> V_45 ;
V_20 = F_18 ( NULL , L_3 , & V_23 , 1 , NULL , NULL ,
& V_39 -> V_2 , & V_46 ,
& V_41 -> V_2 , & V_47 , 0 ) ;
if ( F_14 ( V_20 ) ) {
F_15 ( V_41 ) ;
F_15 ( V_39 ) ;
}
return V_20 ;
}
static struct V_20 * T_2 F_19 ( struct V_21 * V_22 )
{
const char * V_23 = L_4 ;
struct V_48 * div ;
struct V_40 * V_41 ;
struct V_20 * V_20 ;
div = F_11 ( sizeof( * div ) , V_26 ) ;
if ( ! div )
return F_12 ( - V_27 ) ;
div -> V_8 = V_22 -> V_8 + V_49 ;
div -> V_50 = 4 ;
div -> V_51 = V_52 ;
div -> V_45 = & V_22 -> V_45 ;
V_41 = F_11 ( sizeof( * V_41 ) , V_26 ) ;
if ( ! V_41 ) {
F_15 ( div ) ;
return F_12 ( - V_27 ) ;
}
V_41 -> V_8 = V_22 -> V_8 + V_49 ;
V_41 -> V_43 = 8 ;
V_41 -> V_31 = V_44 ;
V_41 -> V_45 = & V_22 -> V_45 ;
V_20 = F_18 ( NULL , L_5 , & V_23 , 1 , NULL , NULL ,
& div -> V_2 , & V_53 ,
& V_41 -> V_2 , & V_47 , 0 ) ;
if ( F_14 ( V_20 ) ) {
F_15 ( V_41 ) ;
F_15 ( div ) ;
}
return V_20 ;
}
static struct V_20 * T_2
F_20 ( struct V_36 * V_37 , struct V_21 * V_22 ,
const struct V_54 * V_55 ,
const char * V_28 )
{
const struct V_56 * V_51 = NULL ;
const char * V_23 ;
unsigned int V_57 ;
unsigned int V_6 = 1 ;
unsigned int div = 1 ;
if ( ! strcmp ( V_28 , L_6 ) ) {
V_23 = F_17 ( V_37 , 0 ) ;
div = V_55 -> V_58 ;
} else if ( ! strcmp ( V_28 , L_1 ) ) {
T_1 V_59 = F_3 ( V_22 -> V_8 + V_60 ) ;
V_23 = L_6 ;
V_6 = ( ( V_59 >> 24 ) & ( ( 1 << 7 ) - 1 ) ) + 1 ;
} else if ( ! strcmp ( V_28 , L_4 ) ) {
V_23 = L_6 ;
V_6 = V_55 -> V_61 / 2 ;
} else if ( ! strcmp ( V_28 , L_7 ) ) {
V_23 = L_6 ;
V_6 = V_55 -> V_62 ;
} else if ( ! strcmp ( V_28 , L_8 ) ) {
V_23 = L_4 ;
div = V_63 & F_21 ( 18 ) ? 36 : 24 ;
} else if ( ! strcmp ( V_28 , L_9 ) ) {
V_23 = L_10 ;
div = ( V_63 & ( F_21 ( 3 ) | F_21 ( 2 ) | F_21 ( 1 ) ) ) == F_21 ( 2 )
? 8 : 10 ;
} else if ( ! strcmp ( V_28 , L_11 ) ) {
V_23 = L_4 ;
V_51 = V_64 ;
V_57 = 8 ;
} else if ( ! strcmp ( V_28 , L_12 ) ) {
V_23 = L_4 ;
V_51 = V_65 ;
V_57 = 4 ;
} else if ( ! strcmp ( V_28 , L_13 ) ) {
V_23 = L_4 ;
V_51 = V_65 ;
V_57 = 0 ;
} else if ( ! strcmp ( V_28 , L_2 ) ) {
return F_10 ( V_22 ) ;
} else if ( ! strcmp ( V_28 , L_3 ) ) {
return F_16 ( V_22 , V_37 ) ;
} else if ( ! strcmp ( V_28 , L_5 ) ) {
return F_19 ( V_22 ) ;
} else {
return F_12 ( - V_66 ) ;
}
if ( ! V_51 )
return F_22 ( NULL , V_28 , V_23 , 0 ,
V_6 , div ) ;
else
return F_23 ( NULL , V_28 , V_23 , 0 ,
V_22 -> V_8 + V_67 , V_57 ,
4 , 0 , V_51 , & V_22 -> V_45 ) ;
}
static void T_2 F_24 ( struct V_36 * V_37 )
{
const struct V_54 * V_55 ;
struct V_21 * V_22 ;
struct V_20 * * V_68 ;
unsigned int V_15 ;
int V_69 ;
V_69 = F_25 ( V_37 , L_14 ) ;
if ( V_69 < 0 ) {
F_26 ( L_15 , V_70 ) ;
return;
}
V_22 = F_11 ( sizeof( * V_22 ) , V_26 ) ;
V_68 = F_11 ( V_69 * sizeof( * V_68 ) , V_26 ) ;
if ( V_22 == NULL || V_68 == NULL ) {
F_26 ( L_16 , V_70 ) ;
return;
}
F_27 ( & V_22 -> V_45 ) ;
V_22 -> V_71 . V_68 = V_68 ;
V_22 -> V_71 . V_72 = V_69 ;
V_22 -> V_8 = F_28 ( V_37 , 0 ) ;
if ( F_29 ( V_22 -> V_8 == NULL ) )
return;
V_55 = & V_73 [ F_30 ( V_63 ) ] ;
for ( V_15 = 0 ; V_15 < V_69 ; ++ V_15 ) {
const char * V_28 ;
struct V_20 * V_20 ;
F_31 ( V_37 , L_14 , V_15 ,
& V_28 ) ;
V_20 = F_20 ( V_37 , V_22 , V_55 , V_28 ) ;
if ( F_14 ( V_20 ) )
F_26 ( L_17 ,
V_70 , V_37 -> V_28 , V_28 , F_32 ( V_20 ) ) ;
else
V_22 -> V_71 . V_68 [ V_15 ] = V_20 ;
}
F_33 ( V_37 , V_74 , & V_22 -> V_71 ) ;
}
void T_2 F_34 ( T_1 V_75 )
{
V_63 = V_75 ;
F_35 ( NULL ) ;
}
