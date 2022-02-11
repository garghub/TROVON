static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned long V_5 , V_6 , V_7 ;
T_1 V_8 = V_9 ;
while ( ( V_5 = F_2 ( & V_4 -> V_10 -> V_5 ) ) & V_11 ) {
V_6 = F_2 ( & V_4 -> V_10 -> V_6 ) ;
V_7 = ( V_5 & V_12 ) ? V_13 : 0 ;
V_7 |= ( V_5 & V_14 ) ? V_15 : 0 ;
if ( V_7 )
F_3 ( 0 , & V_4 -> V_10 -> V_5 ) ;
F_4 ( V_4 -> V_16 , V_6 , V_7 ) ;
V_8 = V_17 ;
}
return V_8 ;
}
static int F_5 ( struct V_18 * V_16 , unsigned char V_19 )
{
struct V_3 * V_4 = V_16 -> V_20 ;
unsigned int V_21 = 10000 ;
while ( ( F_2 ( & V_4 -> V_10 -> V_5 ) & V_22 ) && V_21 -- )
F_6 ( 10 ) ;
if ( ( F_2 ( & V_4 -> V_10 -> V_5 ) & V_22 ) == 0 ) {
F_3 ( V_19 , & V_4 -> V_10 -> V_6 ) ;
F_3 ( V_23 | V_24 | V_25 ,
& V_4 -> V_10 -> V_26 ) ;
return 0 ;
}
return - V_27 ;
}
static int F_7 ( struct V_18 * V_16 )
{
struct V_3 * V_4 = V_16 -> V_20 ;
int V_28 ;
unsigned long V_29 ;
F_3 ( 0 , & V_4 -> V_10 -> V_5 ) ;
V_28 = 1024 ;
while ( ( F_2 ( & V_4 -> V_10 -> V_5 ) & V_11 ) && -- V_28 )
V_29 = F_2 ( & V_4 -> V_10 -> V_6 ) ;
F_3 ( V_23 | V_24 , & V_4 -> V_10 -> V_26 ) ;
return 0 ;
}
static void F_8 ( struct V_18 * V_16 )
{
struct V_3 * V_4 = V_16 -> V_20 ;
F_3 ( 0 , & V_4 -> V_10 -> V_26 ) ;
}
static int F_9 ( struct V_30 * V_31 )
{
struct V_3 * V_4 ;
int V_1 , V_32 ;
T_2 V_33 ;
struct V_34 * V_35 ;
V_4 = F_10 ( & V_31 -> V_36 , sizeof( * V_4 ) , V_37 ) ;
if ( ! V_4 ) {
F_11 ( & V_31 -> V_36 , L_1 ) ;
return - V_38 ;
}
V_35 = F_12 ( V_31 , V_39 , 0 ) ;
V_4 -> V_10 = F_13 ( & V_31 -> V_36 , V_35 ) ;
if ( F_14 ( V_4 -> V_10 ) )
return F_15 ( V_4 -> V_10 ) ;
F_3 ( 0 , & V_4 -> V_10 -> V_26 ) ;
V_1 = F_16 ( V_31 -> V_36 . V_40 , 0 ) ;
V_32 = F_17 ( & V_31 -> V_36 , V_1 , F_1 ,
V_41 , L_2 , V_4 ) ;
if ( V_32 ) {
F_11 ( & V_31 -> V_36 , L_3 , V_1 ) ;
return V_32 ;
}
if ( F_18 ( V_31 -> V_36 . V_40 , L_4 , & V_33 ) ) {
F_11 ( & V_31 -> V_36 , L_5 ) ;
return - V_42 ;
}
F_3 ( V_33 / 10000 , & V_4 -> V_10 -> V_43 ) ;
V_4 -> V_16 = F_19 ( sizeof( struct V_18 ) , V_37 ) ;
if ( ! V_4 -> V_16 )
return - V_38 ;
V_4 -> V_16 -> V_44 . type = V_45 ;
V_4 -> V_16 -> V_46 = F_7 ;
V_4 -> V_16 -> V_47 = F_8 ;
V_4 -> V_16 -> V_48 = F_5 ;
V_4 -> V_16 -> V_20 = V_4 ;
F_20 ( V_4 -> V_16 -> V_49 , L_6 , sizeof( V_4 -> V_16 -> V_49 ) ) ;
snprintf ( V_4 -> V_16 -> V_50 , sizeof( V_4 -> V_16 -> V_50 ) ,
L_7 , V_51 ++ ) ;
F_21 ( & V_31 -> V_36 , L_8 , V_1 , V_4 -> V_10 ) ;
F_22 ( V_4 -> V_16 ) ;
F_23 ( V_31 , V_4 ) ;
return 0 ;
}
static int F_24 ( struct V_30 * V_52 )
{
struct V_3 * V_4 = F_25 ( V_52 ) ;
F_26 ( V_4 -> V_16 ) ;
return 0 ;
}
