static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( L_1 ) ;
V_4 = V_2 -> V_5 -> V_6 ;
V_4 -> V_7 = V_2 ;
F_3 ( V_4 -> V_8 ) ;
F_4 ( V_4 -> V_8 , V_9 ) ;
F_5 ( V_10 , & V_4 -> V_11 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = V_2 -> V_5 -> V_6 ;
F_4 ( V_4 -> V_8 , V_12 ) ;
F_7 ( V_10 , & V_4 -> V_11 ) ;
V_4 -> V_7 = NULL ;
F_8 ( V_4 -> V_8 ) ;
return 0 ;
}
static void F_9 ( struct V_3 * V_4 )
{
T_1 V_13 ;
V_13 = F_10 ( V_4 -> V_8 -> V_14 + V_15 ) ;
F_11 ( V_13 , V_4 -> V_8 -> V_14 + V_16 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
int V_17 )
{
unsigned long V_18 ;
struct V_3 * V_4 ;
F_2 ( L_2 , V_17 ) ;
V_4 = V_2 -> V_5 -> V_6 ;
F_13 ( & V_4 -> V_19 , V_18 ) ;
if ( V_17 ) {
if ( ! F_14 ( V_20 ,
& V_4 -> V_11 ) )
F_9 ( V_4 ) ;
} else {
F_7 ( V_20 , & V_4 -> V_11 ) ;
}
F_15 ( & V_4 -> V_19 , V_18 ) ;
if ( V_17 )
F_16 ( V_4 ) ;
}
void F_16 ( void * V_21 )
{
unsigned long V_18 ;
struct V_3 * V_4 = V_21 ;
void * V_22 = V_4 -> V_8 -> V_23 + V_24 ;
F_13 ( & V_4 -> V_19 , V_18 ) ;
while ( F_10 ( V_4 -> V_8 -> V_14 + V_15 ) !=
F_10 ( V_4 -> V_8 -> V_14 + V_16 ) ) {
T_1 V_25 , V_26 ;
V_26 = F_10 ( V_22 + 2 * F_10 ( V_4 -> V_8 -> V_14 + V_16 ) ) ;
if ( F_17 ( V_20 ,
& V_4 -> V_11 ) )
F_18 ( V_4 -> V_7 ,
( unsigned char * ) & V_26 , 1 ) ;
V_25 = F_10 ( V_4 -> V_8 -> V_14 + V_16 ) + 1 ;
if ( V_25 > F_10 ( V_4 -> V_8 -> V_14 + V_27 ) )
F_11 ( 0 , V_4 -> V_8 -> V_14 + V_16 ) ;
else
F_11 ( V_25 , V_4 -> V_8 -> V_14 + V_16 ) ;
}
F_15 ( & V_4 -> V_19 , V_18 ) ;
}
static void F_19 ( struct V_28 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
F_20 ( V_4 ) ;
}
int F_21 ( struct V_29 * V_30 , int V_31 )
{
struct V_32 * V_33 = V_30 -> V_6 ;
struct V_3 * V_4 ;
struct V_28 * V_5 ;
int V_34 ;
V_34 = F_22 ( V_30 , L_3 , V_31 , 1 , 1 , & V_5 ) ;
if ( V_34 < 0 )
return V_34 ;
V_4 = F_23 ( sizeof( * V_4 ) , V_35 ) ;
if ( V_4 == NULL ) {
F_24 ( V_30 , V_5 ) ;
return - V_36 ;
}
V_4 -> V_8 = V_33 ;
V_33 -> V_37 = V_4 ;
V_5 -> V_6 = V_4 ;
V_5 -> V_38 = F_19 ;
F_25 ( & V_4 -> V_19 ) ;
strcpy ( V_5 -> V_39 , L_4 ) ;
F_26 ( V_5 , V_40 ,
& V_41 ) ;
V_5 -> V_42 |= V_43 ;
return 0 ;
}
