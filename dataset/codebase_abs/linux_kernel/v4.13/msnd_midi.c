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
T_1 V_25 , V_13 , V_26 ;
F_13 ( & V_4 -> V_19 , V_18 ) ;
V_25 = F_10 ( V_4 -> V_8 -> V_14 + V_16 ) ;
V_13 = F_10 ( V_4 -> V_8 -> V_14 + V_15 ) ;
V_26 = F_10 ( V_4 -> V_8 -> V_14 + V_27 ) ;
if ( V_25 > V_26 || V_13 > V_26 )
goto V_28;
while ( V_25 != V_13 ) {
unsigned char V_29 = F_10 ( V_22 + 2 * V_25 ) ;
if ( F_17 ( V_20 , & V_4 -> V_11 ) )
F_18 ( V_4 -> V_7 , & V_29 , 1 ) ;
if ( ++ V_25 > V_26 )
V_25 = 0 ;
F_11 ( V_25 , V_4 -> V_8 -> V_14 + V_16 ) ;
}
V_28:
F_15 ( & V_4 -> V_19 , V_18 ) ;
}
static void F_19 ( struct V_30 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
F_20 ( V_4 ) ;
}
int F_21 ( struct V_31 * V_32 , int V_33 )
{
struct V_34 * V_35 = V_32 -> V_6 ;
struct V_3 * V_4 ;
struct V_30 * V_5 ;
int V_36 ;
V_36 = F_22 ( V_32 , L_3 , V_33 , 1 , 1 , & V_5 ) ;
if ( V_36 < 0 )
return V_36 ;
V_4 = F_23 ( sizeof( * V_4 ) , V_37 ) ;
if ( V_4 == NULL ) {
F_24 ( V_32 , V_5 ) ;
return - V_38 ;
}
V_4 -> V_8 = V_35 ;
V_35 -> V_39 = V_4 ;
V_5 -> V_6 = V_4 ;
V_5 -> V_40 = F_19 ;
F_25 ( & V_4 -> V_19 ) ;
strcpy ( V_5 -> V_41 , L_4 ) ;
F_26 ( V_5 , V_42 ,
& V_43 ) ;
V_5 -> V_44 |= V_45 ;
return 0 ;
}
