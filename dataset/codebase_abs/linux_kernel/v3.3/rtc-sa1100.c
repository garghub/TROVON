static inline int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 == - 1 ) ||
( ( unsigned ) V_2 -> V_4 >= 12 ) ||
( ( unsigned ) ( V_2 -> V_5 - 1 ) >= 31 ) ||
( ( unsigned ) V_2 -> V_6 > 23 ) ||
( ( unsigned ) V_2 -> V_7 > 59 ) ||
( ( unsigned ) V_2 -> V_8 > 59 ) ;
}
static void F_2 ( struct V_1 * V_9 , struct V_1 * V_10 ,
struct V_1 * V_11 )
{
unsigned long V_12 ;
unsigned long V_13 ;
V_9 -> V_3 = V_10 -> V_3 ;
V_9 -> V_4 = V_10 -> V_4 ;
V_9 -> V_5 = V_10 -> V_5 ;
V_9 -> V_6 = V_11 -> V_6 ;
V_9 -> V_7 = V_11 -> V_7 ;
V_9 -> V_8 = V_11 -> V_8 ;
F_3 ( V_10 , & V_13 ) ;
F_3 ( V_9 , & V_12 ) ;
if ( V_12 < V_13 ) {
V_12 += 60 * 60 * 24 ;
F_4 ( V_12 , V_9 ) ;
}
}
static int F_5 ( struct V_1 * V_11 )
{
struct V_1 V_14 , V_15 ;
unsigned long V_10 , time ;
int V_16 ;
do {
V_10 = V_17 ;
F_4 ( V_10 , & V_15 ) ;
F_2 ( & V_14 , & V_15 , V_11 ) ;
V_16 = F_3 ( & V_14 , & time ) ;
if ( V_16 != 0 )
break;
V_18 = V_18 & ( V_19 | V_20 | V_21 ) ;
V_22 = time ;
} while ( V_10 != V_17 );
return V_16 ;
}
static T_1 F_6 ( int V_23 , void * V_24 )
{
struct V_25 * V_26 = F_7 ( V_24 ) ;
struct V_27 * V_28 = F_8 ( V_26 ) ;
unsigned int V_29 ;
unsigned long V_30 = 0 ;
F_9 ( & V_31 ) ;
V_29 = V_18 ;
V_18 = 0 ;
if ( V_29 & ( V_20 | V_19 ) ) {
V_18 = ( V_21 | V_32 ) & ( V_29 >> 2 ) ;
} else {
V_18 = V_21 | V_32 ;
}
if ( V_29 & V_21 )
V_29 &= ~ V_20 ;
V_18 = V_29 & ( V_20 | V_19 ) ;
if ( V_29 & V_21 )
V_30 |= V_33 | V_34 ;
if ( V_29 & V_32 )
V_30 |= V_35 | V_34 ;
F_10 ( V_28 , 1 , V_30 ) ;
if ( V_29 & V_21 && F_1 ( & V_36 ) )
F_5 ( & V_36 ) ;
F_11 ( & V_31 ) ;
return V_37 ;
}
static int F_12 ( struct V_38 * V_39 )
{
int V_16 ;
struct V_25 * V_40 = F_7 ( V_39 ) ;
struct V_27 * V_28 = F_8 ( V_40 ) ;
V_16 = F_13 ( V_41 , F_6 , V_42 ,
L_1 , V_39 ) ;
if ( V_16 ) {
F_14 ( V_39 , L_2 , V_41 ) ;
goto V_43;
}
V_16 = F_13 ( V_44 , F_6 , V_42 ,
L_3 , V_39 ) ;
if ( V_16 ) {
F_14 ( V_39 , L_2 , V_44 ) ;
goto V_45;
}
V_28 -> V_46 = V_47 ;
F_15 ( V_28 , NULL , V_47 ) ;
return 0 ;
V_45:
F_16 ( V_41 , V_39 ) ;
V_43:
return V_16 ;
}
static void F_17 ( struct V_38 * V_39 )
{
F_18 ( & V_31 ) ;
V_18 = 0 ;
F_19 ( & V_31 ) ;
F_16 ( V_44 , V_39 ) ;
F_16 ( V_41 , V_39 ) ;
}
static int F_20 ( struct V_38 * V_39 , unsigned int V_48 )
{
F_18 ( & V_31 ) ;
if ( V_48 )
V_18 |= V_20 ;
else
V_18 &= ~ V_20 ;
F_19 ( & V_31 ) ;
return 0 ;
}
static int F_21 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
F_4 ( V_17 , V_2 ) ;
return 0 ;
}
static int F_22 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
unsigned long time ;
int V_16 ;
V_16 = F_3 ( V_2 , & time ) ;
if ( V_16 == 0 )
V_17 = time ;
return V_16 ;
}
static int F_23 ( struct V_38 * V_39 , struct V_49 * V_11 )
{
T_2 V_29 ;
memcpy ( & V_11 -> time , & V_36 , sizeof( struct V_1 ) ) ;
V_29 = V_18 ;
V_11 -> V_48 = ( V_29 & V_20 ) ? 1 : 0 ;
V_11 -> V_50 = ( V_29 & V_21 ) ? 1 : 0 ;
return 0 ;
}
static int F_24 ( struct V_38 * V_39 , struct V_49 * V_11 )
{
int V_16 ;
F_18 ( & V_31 ) ;
V_16 = F_5 ( & V_11 -> time ) ;
if ( V_16 == 0 ) {
if ( V_11 -> V_48 )
V_18 |= V_20 ;
else
V_18 &= ~ V_20 ;
}
F_19 ( & V_31 ) ;
return V_16 ;
}
static int F_25 ( struct V_38 * V_39 , struct V_51 * V_52 )
{
F_26 ( V_52 , L_4 , ( T_2 ) V_53 ) ;
F_26 ( V_52 , L_5 , ( T_2 ) V_18 ) ;
return 0 ;
}
static int F_27 ( struct V_25 * V_26 )
{
struct V_27 * V_28 ;
if ( V_53 == 0 ) {
V_53 = V_54 + ( V_55 << 16 ) ;
F_28 ( & V_26 -> V_39 , L_6
L_7 ) ;
V_17 = 0 ;
}
F_29 ( & V_26 -> V_39 , 1 ) ;
V_28 = F_30 ( V_26 -> V_56 , & V_26 -> V_39 , & V_57 ,
V_58 ) ;
if ( F_31 ( V_28 ) )
return F_32 ( V_28 ) ;
F_33 ( V_26 , V_28 ) ;
V_18 = V_21 | V_32 ;
return 0 ;
}
static int F_34 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_8 ( V_26 ) ;
if ( V_28 )
F_35 ( V_28 ) ;
return 0 ;
}
static int F_36 ( struct V_38 * V_39 )
{
if ( F_37 ( V_39 ) )
F_38 ( V_44 ) ;
return 0 ;
}
static int F_39 ( struct V_38 * V_39 )
{
if ( F_37 ( V_39 ) )
F_40 ( V_44 ) ;
return 0 ;
}
