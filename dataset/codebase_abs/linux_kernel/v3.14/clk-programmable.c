static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_2 ( & V_4 -> V_5 ) ;
return V_6 ;
}
static int F_3 ( struct V_7 * V_8 )
{
T_2 V_9 ;
struct V_3 * V_4 = F_4 ( V_8 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
const struct V_12 * V_13 = V_4 -> V_13 ;
T_3 V_14 = V_4 -> V_14 ;
T_2 V_15 = F_5 ( V_14 ) ;
V_9 = V_4 -> V_16 | ( V_4 -> V_17 << V_13 -> V_18 ) ;
if ( V_13 -> V_19 && V_4 -> V_20 )
V_9 |= V_21 ;
F_6 ( V_11 , F_7 ( V_14 ) , V_9 ) ;
while ( ! ( F_8 ( V_11 , V_22 ) & V_15 ) )
F_9 ( V_4 -> V_5 , F_8 ( V_11 , V_22 ) & V_15 ) ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_4 ( V_8 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
return ! ! ( F_8 ( V_11 , V_22 ) & F_7 ( V_4 -> V_14 ) ) ;
}
static unsigned long F_11 ( struct V_7 * V_8 ,
unsigned long V_23 )
{
T_2 V_9 ;
struct V_3 * V_4 = F_4 ( V_8 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
const struct V_12 * V_13 = V_4 -> V_13 ;
V_9 = F_8 ( V_11 , F_7 ( V_4 -> V_14 ) ) ;
V_4 -> V_17 = ( V_9 >> V_13 -> V_18 ) & V_24 ;
return V_23 >> V_4 -> V_17 ;
}
static long F_12 ( struct V_7 * V_8 , unsigned long V_25 ,
unsigned long * V_23 )
{
unsigned long V_26 = * V_23 ;
unsigned long V_27 ;
unsigned long V_28 ;
unsigned long V_29 ;
int V_30 = V_30 ;
if ( V_25 > * V_23 )
return * V_23 ;
else
V_27 = * V_23 - V_25 ;
if ( ! V_27 )
return V_26 ;
for ( V_30 = 1 ; V_30 < V_24 ; V_30 ++ ) {
V_29 = * V_23 >> V_30 ;
if ( V_29 > V_25 )
V_28 = V_29 - V_25 ;
else
V_28 = V_25 - V_29 ;
if ( ! V_28 )
return V_29 ;
if ( V_28 < V_27 ) {
V_27 = V_28 ;
V_26 = V_29 ;
}
if ( V_25 > V_29 )
break;
}
return V_26 ;
}
static int F_13 ( struct V_7 * V_8 , T_3 V_31 )
{
struct V_3 * V_4 = F_4 ( V_8 ) ;
const struct V_12 * V_13 = V_4 -> V_13 ;
if ( V_31 > V_13 -> V_32 ) {
if ( V_31 > V_33 && V_13 -> V_19 ) {
V_4 -> V_16 = 0 ;
V_4 -> V_20 = 1 ;
return 0 ;
} else {
return - V_34 ;
}
}
V_4 -> V_16 = V_31 ;
return 0 ;
}
static T_3 F_14 ( struct V_7 * V_8 )
{
T_2 V_9 ;
T_3 V_35 ;
struct V_3 * V_4 = F_4 ( V_8 ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
const struct V_12 * V_13 = V_4 -> V_13 ;
V_9 = F_8 ( V_11 , F_7 ( V_4 -> V_14 ) ) ;
V_4 -> V_16 = V_9 & V_13 -> V_32 ;
V_35 = V_4 -> V_16 ;
if ( V_13 -> V_19 ) {
V_4 -> V_20 = ! ! ( V_9 & V_21 ) ;
if ( V_4 -> V_20 && ! V_35 )
V_35 = V_33 + 1 ;
}
return V_35 ;
}
static int F_15 ( struct V_7 * V_8 , unsigned long V_25 ,
unsigned long V_23 )
{
struct V_3 * V_4 = F_4 ( V_8 ) ;
unsigned long V_26 = V_23 ;
unsigned long V_27 ;
unsigned long V_28 ;
unsigned long V_29 ;
int V_30 = 0 ;
if ( V_25 > V_23 )
return V_23 ;
else
V_27 = V_23 - V_25 ;
if ( ! V_27 ) {
V_4 -> V_17 = V_30 ;
return 0 ;
}
for ( V_30 = 1 ; V_30 < V_24 ; V_30 ++ ) {
V_29 = V_23 >> V_30 ;
if ( V_29 > V_25 )
V_28 = V_29 - V_25 ;
else
V_28 = V_25 - V_29 ;
if ( ! V_28 )
break;
if ( V_28 < V_27 ) {
V_27 = V_28 ;
V_26 = V_29 ;
}
if ( V_25 > V_29 )
break;
}
V_4 -> V_17 = V_30 ;
return 0 ;
}
static struct V_36 * T_4
F_16 ( struct V_10 * V_11 , unsigned int V_1 ,
const char * V_37 , const char * * V_38 ,
T_3 V_39 , T_3 V_14 ,
const struct V_12 * V_13 )
{
int V_35 ;
struct V_3 * V_4 ;
struct V_36 * V_36 = NULL ;
struct V_40 V_41 ;
char V_42 [ 11 ] ;
if ( V_14 > V_43 )
return F_17 ( - V_34 ) ;
V_4 = F_18 ( sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 )
return F_17 ( - V_45 ) ;
V_41 . V_37 = V_37 ;
V_41 . V_46 = & V_47 ;
V_41 . V_38 = V_38 ;
V_41 . V_39 = V_39 ;
V_41 . V_48 = V_49 | V_50 ;
V_4 -> V_14 = V_14 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_8 . V_41 = & V_41 ;
V_4 -> V_11 = V_11 ;
V_4 -> V_1 = V_1 ;
F_19 ( & V_4 -> V_5 ) ;
F_20 ( V_4 -> V_1 , V_51 ) ;
snprintf ( V_42 , sizeof( V_42 ) , L_1 , V_14 ) ;
V_35 = F_21 ( V_4 -> V_1 , F_1 ,
V_52 , V_42 , V_4 ) ;
if ( V_35 )
return F_17 ( V_35 ) ;
V_36 = F_22 ( NULL , & V_4 -> V_8 ) ;
if ( F_23 ( V_36 ) )
F_24 ( V_4 ) ;
return V_36 ;
}
static void T_4
F_25 ( struct V_53 * V_54 , struct V_10 * V_11 ,
const struct V_12 * V_13 )
{
int V_55 ;
T_2 V_14 ;
int V_56 ;
unsigned int V_1 ;
struct V_36 * V_36 ;
int V_39 ;
const char * V_38 [ V_57 ] ;
const char * V_37 ;
struct V_53 * V_58 ;
V_39 = F_26 ( V_54 , L_2 , L_3 ) ;
if ( V_39 <= 0 || V_39 > V_57 )
return;
for ( V_56 = 0 ; V_56 < V_39 ; ++ V_56 ) {
V_38 [ V_56 ] = F_27 ( V_54 , V_56 ) ;
if ( ! V_38 [ V_56 ] )
return;
}
V_55 = F_28 ( V_54 ) ;
if ( ! V_55 || V_55 > ( V_43 + 1 ) )
return;
F_29 (np, progclknp) {
if ( F_30 ( V_58 , L_4 , & V_14 ) )
continue;
if ( F_31 ( V_54 , L_5 , & V_37 ) )
V_37 = V_58 -> V_37 ;
V_1 = F_32 ( V_58 , 0 ) ;
if ( ! V_1 )
continue;
V_36 = F_16 ( V_11 , V_1 , V_37 ,
V_38 , V_39 ,
V_14 , V_13 ) ;
if ( F_23 ( V_36 ) )
continue;
F_33 ( V_58 , V_59 , V_36 ) ;
}
}
void T_4 F_34 ( struct V_53 * V_54 ,
struct V_10 * V_11 )
{
F_25 ( V_54 , V_11 , & V_60 ) ;
}
void T_4 F_35 ( struct V_53 * V_54 ,
struct V_10 * V_11 )
{
F_25 ( V_54 , V_11 , & V_61 ) ;
}
void T_4 F_36 ( struct V_53 * V_54 ,
struct V_10 * V_11 )
{
F_25 ( V_54 , V_11 , & V_62 ) ;
}
