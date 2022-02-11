static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
T_2 V_6 = F_3 ( V_5 ) ;
if ( V_6 & V_7 )
return 0 ;
F_4 ( V_6 | V_8 , V_5 ) ;
F_5 ( V_4 -> V_9 , V_4 -> V_9 + 1 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
T_2 V_6 = F_3 ( V_5 ) ;
if ( V_6 & V_7 )
return;
F_4 ( V_6 & ~ V_8 , V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
T_2 V_6 = F_3 ( V_5 ) ;
if ( V_6 & V_7 )
return 1 ;
return ! ! ( V_6 & V_8 ) ;
}
static struct V_10 * T_3
F_8 ( void T_1 * V_5 ,
const char * V_11 ,
const char * V_12 ,
unsigned long V_13 ,
bool V_14 )
{
struct V_3 * V_4 ;
struct V_10 * V_10 = NULL ;
struct V_15 V_16 ;
if ( ! V_5 || ! V_11 || ! V_12 )
return F_9 ( - V_17 ) ;
V_4 = F_10 ( sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 )
return F_9 ( - V_19 ) ;
V_16 . V_11 = V_11 ;
V_16 . V_20 = & V_21 ;
V_16 . V_22 = & V_12 ;
V_16 . V_23 = 1 ;
V_16 . V_24 = V_25 ;
V_4 -> V_2 . V_16 = & V_16 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_9 = V_13 ;
if ( V_14 )
F_4 ( ( F_3 ( V_5 ) & ~ V_8 ) | V_7 ,
V_5 ) ;
V_10 = F_11 ( NULL , & V_4 -> V_2 ) ;
if ( F_12 ( V_10 ) )
F_13 ( V_4 ) ;
return V_10 ;
}
void T_3 F_14 ( struct V_26 * V_27 ,
void T_1 * V_5 )
{
struct V_10 * V_10 ;
const char * V_12 ;
const char * V_11 = V_27 -> V_11 ;
T_2 V_13 ;
bool V_14 ;
V_12 = F_15 ( V_27 , 0 ) ;
F_16 ( V_27 , L_1 , & V_11 ) ;
F_17 ( V_27 , L_2 , & V_13 ) ;
V_14 = F_18 ( V_27 , L_3 ) ;
V_10 = F_8 ( V_5 , V_11 , V_12 , V_13 ,
V_14 ) ;
if ( F_12 ( V_10 ) )
return;
F_19 ( V_27 , V_28 , V_10 ) ;
}
static unsigned long F_20 ( struct V_1 * V_2 ,
unsigned long V_29 )
{
struct V_30 * V_4 = F_21 ( V_2 ) ;
return V_4 -> V_31 ;
}
static unsigned long F_22 ( struct V_1 * V_2 ,
unsigned long V_32 )
{
struct V_30 * V_4 = F_21 ( V_2 ) ;
return V_4 -> V_33 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_30 * V_4 = F_21 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
F_4 ( F_3 ( V_5 ) | V_34 , V_5 ) ;
F_5 ( V_4 -> V_9 , V_4 -> V_9 + 1 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_30 * V_4 = F_21 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
F_4 ( F_3 ( V_5 ) & ~ V_34 , V_5 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_30 * V_4 = F_21 ( V_2 ) ;
return ! ! ( F_3 ( V_4 -> V_5 ) & V_34 ) ;
}
static struct V_10 * T_3
F_26 ( void T_1 * V_5 ,
const char * V_11 ,
unsigned long V_31 ,
unsigned long V_33 ,
unsigned long V_13 )
{
struct V_30 * V_4 ;
struct V_10 * V_10 = NULL ;
struct V_15 V_16 ;
if ( ! V_5 || ! V_11 )
return F_9 ( - V_17 ) ;
V_4 = F_10 ( sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 )
return F_9 ( - V_19 ) ;
V_16 . V_11 = V_11 ;
V_16 . V_20 = & V_35 ;
V_16 . V_22 = NULL ;
V_16 . V_23 = 0 ;
V_16 . V_24 = V_36 | V_25 ;
V_4 -> V_2 . V_16 = & V_16 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_31 = V_31 ;
V_4 -> V_33 = V_33 ;
V_4 -> V_9 = V_13 ;
V_10 = F_11 ( NULL , & V_4 -> V_2 ) ;
if ( F_12 ( V_10 ) )
F_13 ( V_4 ) ;
return V_10 ;
}
void T_3 F_27 ( struct V_26 * V_27 ,
void T_1 * V_5 )
{
struct V_10 * V_10 ;
T_2 V_31 = 0 ;
T_2 V_33 = 0 ;
T_2 V_13 = 0 ;
const char * V_11 = V_27 -> V_11 ;
F_16 ( V_27 , L_1 , & V_11 ) ;
F_17 ( V_27 , L_4 , & V_31 ) ;
F_17 ( V_27 , L_5 , & V_33 ) ;
F_17 ( V_27 , L_2 , & V_13 ) ;
V_10 = F_26 ( V_5 , V_11 , V_31 , V_33 ,
V_13 ) ;
if ( F_12 ( V_10 ) )
return;
F_19 ( V_27 , V_28 , V_10 ) ;
}
static int F_28 ( struct V_1 * V_2 , T_4 V_37 )
{
struct V_38 * V_39 = F_29 ( V_2 ) ;
void T_1 * V_5 = V_39 -> V_5 ;
T_2 V_6 ;
if ( V_37 > 1 )
return - V_17 ;
V_6 = F_3 ( V_5 ) ;
if ( ( ! V_37 && ! ( V_6 & V_40 ) ) ||
( V_37 && ( V_6 & V_40 ) ) )
return 0 ;
if ( V_37 )
V_6 |= V_40 ;
else
V_6 &= ~ V_40 ;
F_4 ( V_6 , V_5 ) ;
F_5 ( V_41 , V_41 + 1 ) ;
return 0 ;
}
static T_4 F_30 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_29 ( V_2 ) ;
return ! ! ( F_3 ( V_39 -> V_5 ) & V_40 ) ;
}
static struct V_10 * T_3
F_31 ( void T_1 * V_5 ,
const char * V_11 ,
const char * * V_22 ,
int V_23 )
{
struct V_38 * V_39 ;
struct V_10 * V_10 = NULL ;
struct V_15 V_16 ;
if ( ! V_5 || ! V_11 || ! V_22 || ! V_23 )
return F_9 ( - V_17 ) ;
V_39 = F_10 ( sizeof( * V_39 ) , V_18 ) ;
if ( ! V_39 )
return F_9 ( - V_19 ) ;
V_16 . V_11 = V_11 ;
V_16 . V_20 = & V_42 ;
V_16 . V_22 = V_22 ;
V_16 . V_23 = V_23 ;
V_16 . V_24 = 0 ;
V_39 -> V_2 . V_16 = & V_16 ;
V_39 -> V_5 = V_5 ;
V_39 -> V_43 = ! ! ( F_3 ( V_5 ) & V_40 ) ;
V_10 = F_11 ( NULL , & V_39 -> V_2 ) ;
if ( F_12 ( V_10 ) )
F_13 ( V_39 ) ;
return V_10 ;
}
void T_3 F_32 ( struct V_26 * V_27 ,
void T_1 * V_5 )
{
struct V_10 * V_10 ;
const char * V_22 [ 2 ] ;
int V_23 ;
const char * V_11 = V_27 -> V_11 ;
int V_44 ;
V_23 = F_33 ( V_27 , L_6 , L_7 ) ;
if ( V_23 <= 0 || V_23 > 2 )
return;
for ( V_44 = 0 ; V_44 < V_23 ; ++ V_44 ) {
V_22 [ V_44 ] = F_15 ( V_27 , V_44 ) ;
if ( ! V_22 [ V_44 ] )
return;
}
F_16 ( V_27 , L_1 , & V_11 ) ;
V_10 = F_31 ( V_5 , V_11 , V_22 ,
V_23 ) ;
if ( F_12 ( V_10 ) )
return;
F_19 ( V_27 , V_28 , V_10 ) ;
}
static T_4 F_34 ( struct V_1 * V_2 )
{
struct V_45 * V_39 = F_35 ( V_2 ) ;
return ! ! ( F_36 ( V_39 -> V_46 , V_47 ) & V_48 ) ;
}
static struct V_10 * T_3
F_37 ( struct V_49 * V_46 ,
const char * V_11 ,
const char * * V_22 ,
int V_23 )
{
struct V_45 * V_39 ;
struct V_10 * V_10 = NULL ;
struct V_15 V_16 ;
if ( ! V_46 || ! V_11 )
return F_9 ( - V_17 ) ;
if ( ! V_22 || ! V_23 )
return F_9 ( - V_17 ) ;
V_39 = F_10 ( sizeof( * V_39 ) , V_18 ) ;
if ( ! V_39 )
return F_9 ( - V_19 ) ;
V_16 . V_11 = V_11 ;
V_16 . V_20 = & V_50 ;
V_16 . V_22 = V_22 ;
V_16 . V_23 = V_23 ;
V_16 . V_24 = 0 ;
V_39 -> V_2 . V_16 = & V_16 ;
V_39 -> V_46 = V_46 ;
V_10 = F_11 ( NULL , & V_39 -> V_2 ) ;
if ( F_12 ( V_10 ) )
F_13 ( V_39 ) ;
return V_10 ;
}
void T_3 F_38 ( struct V_26 * V_27 ,
struct V_49 * V_46 )
{
struct V_10 * V_10 ;
const char * V_22 [ 2 ] ;
int V_23 ;
const char * V_11 = V_27 -> V_11 ;
int V_44 ;
V_23 = F_33 ( V_27 , L_6 , L_7 ) ;
if ( V_23 != 2 )
return;
for ( V_44 = 0 ; V_44 < V_23 ; ++ V_44 ) {
V_22 [ V_44 ] = F_15 ( V_27 , V_44 ) ;
if ( ! V_22 [ V_44 ] )
return;
}
F_16 ( V_27 , L_1 , & V_11 ) ;
V_10 = F_37 ( V_46 , V_11 , V_22 ,
V_23 ) ;
if ( F_12 ( V_10 ) )
return;
F_19 ( V_27 , V_28 , V_10 ) ;
}
