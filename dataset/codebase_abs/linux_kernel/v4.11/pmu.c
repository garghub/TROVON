static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_7 ;
F_3 ( & V_5 -> V_8 , V_6 ) ;
V_7 = F_4 ( V_5 -> V_9 + V_10 ) ;
F_5 ( V_7 & ~ F_6 ( V_3 ) , V_5 -> V_9 + V_10 ) ;
F_5 ( V_7 | F_6 ( V_3 ) , V_5 -> V_9 + V_10 ) ;
F_7 ( & V_5 -> V_8 , V_6 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_7 = ~ F_6 ( V_3 ) ;
F_3 ( & V_5 -> V_8 , V_6 ) ;
V_7 &= F_4 ( V_5 -> V_9 + V_10 ) ;
F_5 ( V_7 , V_5 -> V_9 + V_10 ) ;
F_7 ( & V_5 -> V_8 , V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_7 = F_6 ( V_3 ) ;
F_3 ( & V_5 -> V_8 , V_6 ) ;
V_7 |= F_4 ( V_5 -> V_9 + V_10 ) ;
F_5 ( V_7 , V_5 -> V_9 + V_10 ) ;
F_7 ( & V_5 -> V_8 , V_6 ) ;
return 0 ;
}
static void T_2 F_10 ( struct V_4 * V_5 )
{
int V_11 ;
V_5 -> V_12 = V_13 ;
V_5 -> V_12 . V_14 = V_5 -> V_14 ;
V_11 = F_11 ( & V_5 -> V_12 ) ;
if ( V_11 )
F_12 ( L_1 , L_2 , V_11 ) ;
}
static void T_2 F_10 ( struct V_4 * V_5 )
{
}
static int F_13 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_14 ( V_16 ) ;
struct V_4 * V_5 = V_18 -> V_5 ;
unsigned long V_6 ;
unsigned int V_7 ;
void T_3 * V_19 = V_5 -> V_19 ;
void T_3 * V_9 = V_5 -> V_9 ;
F_3 ( & V_5 -> V_8 , V_6 ) ;
if ( V_18 -> V_20 ) {
V_7 = ~ V_18 -> V_20 ;
V_7 &= F_4 ( V_19 + V_21 ) ;
F_5 ( V_7 , V_19 + V_21 ) ;
}
if ( V_18 -> V_22 ) {
V_7 = ~ V_18 -> V_22 ;
V_7 &= F_4 ( V_9 + V_10 ) ;
F_5 ( V_7 , V_9 + V_10 ) ;
}
V_7 = F_4 ( V_19 + V_23 ) | V_18 -> V_24 ;
F_5 ( V_7 , V_19 + V_23 ) ;
F_7 ( & V_5 -> V_8 , V_6 ) ;
return 0 ;
}
static int F_15 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_14 ( V_16 ) ;
struct V_4 * V_5 = V_18 -> V_5 ;
unsigned long V_6 ;
unsigned int V_7 ;
void T_3 * V_19 = V_5 -> V_19 ;
void T_3 * V_9 = V_5 -> V_9 ;
F_3 ( & V_5 -> V_8 , V_6 ) ;
V_7 = ~ V_18 -> V_24 & F_4 ( V_19 + V_23 ) ;
F_5 ( V_7 , V_19 + V_23 ) ;
if ( V_18 -> V_22 ) {
V_7 = V_18 -> V_22 ;
V_7 |= F_4 ( V_9 + V_10 ) ;
F_5 ( V_7 , V_9 + V_10 ) ;
}
if ( V_18 -> V_20 ) {
V_7 = V_18 -> V_20 ;
V_7 |= F_4 ( V_19 + V_21 ) ;
F_5 ( V_7 , V_19 + V_21 ) ;
}
F_7 ( & V_5 -> V_8 , V_6 ) ;
return 0 ;
}
static void F_16 ( struct V_17 * V_16 ,
struct V_25 * V_26 )
{
unsigned int V_7 = F_4 ( V_16 -> V_5 -> V_19 + V_23 ) ;
V_16 -> V_27 . V_28 = F_13 ;
V_16 -> V_27 . V_29 = F_15 ;
F_17 ( & V_16 -> V_27 , NULL , ! ( V_7 & V_16 -> V_24 ) ) ;
if ( V_26 )
F_18 ( V_26 , & V_16 -> V_27 ) ;
}
static void F_19 ( struct V_30 * V_31 )
{
struct V_4 * V_5 = F_20 ( V_31 ) ;
struct V_32 * V_33 = V_5 -> V_34 ;
struct V_35 * V_16 = V_5 -> V_35 ;
void T_3 * V_27 = V_33 -> V_36 ;
T_1 V_37 = F_4 ( V_27 + V_38 ) & V_33 -> V_39 ;
T_1 V_40 = ~ 0 ;
if ( V_37 == 0 ) {
F_21 ( V_31 ) ;
return;
}
while ( V_37 ) {
T_1 V_41 = F_22 ( V_37 ) - 1 ;
V_37 &= ~ ( 1 << V_41 ) ;
V_40 &= ~ ( 1 << V_41 ) ;
F_23 ( F_24 ( V_16 , V_41 ) ) ;
}
F_25 ( V_33 ) ;
V_40 &= F_4 ( V_27 + V_38 ) ;
F_5 ( V_40 , V_27 + V_38 ) ;
F_26 ( V_33 ) ;
}
static int T_2 F_27 ( struct V_4 * V_5 , int V_42 )
{
const char * V_43 = L_3 ;
struct V_32 * V_33 ;
struct V_35 * V_16 ;
int V_11 ;
F_28 ( 0 , V_5 -> V_9 + V_44 ) ;
F_28 ( 0 , V_5 -> V_9 + V_38 ) ;
V_16 = F_29 ( V_5 -> V_14 , V_45 ,
& V_46 , NULL ) ;
if ( ! V_16 ) {
F_12 ( L_4 , V_43 ) ;
return - V_47 ;
}
V_11 = F_30 ( V_16 , V_45 , 1 , V_43 ,
V_48 ,
V_49 | V_50 , 0 ,
V_51 ) ;
if ( V_11 ) {
F_12 ( L_5 , V_43 , V_11 ) ;
F_31 ( V_16 ) ;
return V_11 ;
}
V_33 = F_32 ( V_16 , 0 ) ;
V_33 -> V_36 = V_5 -> V_9 ;
V_33 -> V_52 [ 0 ] . V_53 . V_54 = V_44 ;
V_33 -> V_52 [ 0 ] . V_55 . V_56 = V_57 ;
V_33 -> V_52 [ 0 ] . V_55 . V_58 = V_59 ;
V_5 -> V_35 = V_16 ;
V_5 -> V_34 = V_33 ;
F_33 ( V_42 , V_5 ) ;
F_34 ( V_42 , F_19 ) ;
return 0 ;
}
int T_2 F_35 ( const struct V_60 * V_61 )
{
const struct V_62 * V_63 ;
struct V_4 * V_5 ;
int V_11 ;
V_5 = F_36 ( sizeof( * V_5 ) , V_64 ) ;
if ( ! V_5 )
return - V_47 ;
F_37 ( & V_5 -> V_8 ) ;
V_5 -> V_9 = V_61 -> V_9 ;
V_5 -> V_19 = V_61 -> V_19 ;
F_10 ( V_5 ) ;
for ( V_63 = V_61 -> V_65 ; V_63 -> V_43 ;
V_63 ++ ) {
struct V_17 * V_16 ;
V_16 = F_36 ( sizeof( * V_16 ) , V_64 ) ;
if ( V_16 ) {
V_16 -> V_5 = V_5 ;
V_16 -> V_24 = V_63 -> V_24 ;
V_16 -> V_22 = V_63 -> V_22 ;
V_16 -> V_20 = V_63 -> V_20 ;
V_16 -> V_27 . V_43 = V_63 -> V_43 ;
F_16 ( V_16 , NULL ) ;
}
}
V_11 = F_27 ( V_5 , V_61 -> V_42 ) ;
if ( V_11 )
F_12 ( L_6 , V_11 ) ;
if ( V_5 -> V_35 )
F_38 ( V_5 -> V_35 ,
V_61 -> V_66 ,
0 , V_45 ) ;
return 0 ;
}
int T_2 F_39 ( void )
{
struct V_25 * V_67 , * V_68 , * V_26 ;
struct V_4 * V_5 ;
int V_11 , V_69 ;
V_67 = F_40 ( NULL , NULL , L_7 ) ;
if ( ! V_67 )
return 0 ;
V_68 = F_41 ( V_67 , L_8 ) ;
if ( ! V_68 ) {
F_12 ( L_9 , V_67 -> V_43 ) ;
return 0 ;
}
V_5 = F_36 ( sizeof( * V_5 ) , V_64 ) ;
if ( ! V_5 )
return - V_47 ;
F_37 ( & V_5 -> V_8 ) ;
V_5 -> V_14 = V_67 ;
V_5 -> V_9 = F_42 ( V_5 -> V_14 , 0 ) ;
V_5 -> V_19 = F_42 ( V_5 -> V_14 , 1 ) ;
if ( ! V_5 -> V_9 || ! V_5 -> V_19 ) {
F_12 ( L_10 , V_67 -> V_43 ) ;
F_43 ( V_5 -> V_19 ) ;
F_43 ( V_5 -> V_9 ) ;
F_44 ( V_5 ) ;
return - V_47 ;
}
F_10 ( V_5 ) ;
F_45 (domains_node, np) {
struct V_70 args ;
struct V_17 * V_16 ;
V_16 = F_36 ( sizeof( * V_16 ) , V_64 ) ;
if ( ! V_16 )
break;
V_16 -> V_5 = V_5 ;
V_16 -> V_27 . V_43 = F_46 ( V_26 -> V_43 , V_64 ) ;
if ( ! V_16 -> V_27 . V_43 ) {
F_44 ( V_16 ) ;
break;
}
F_47 ( V_26 , L_11 ,
& V_16 -> V_24 ) ;
F_47 ( V_26 , L_12 ,
& V_16 -> V_20 ) ;
V_11 = F_48 ( V_26 , L_13 , L_14 ,
0 , & args ) ;
if ( V_11 == 0 ) {
if ( args . V_26 == V_5 -> V_14 )
V_16 -> V_22 = F_6 ( args . args [ 0 ] ) ;
F_49 ( args . V_26 ) ;
}
F_16 ( V_16 , V_26 ) ;
}
V_69 = F_50 ( V_5 -> V_14 , 0 ) ;
if ( ! V_69 ) {
F_12 ( L_15 , V_67 -> V_43 ) ;
} else {
V_11 = F_27 ( V_5 , V_69 ) ;
if ( V_11 )
F_12 ( L_6 , V_11 ) ;
}
return 0 ;
}
