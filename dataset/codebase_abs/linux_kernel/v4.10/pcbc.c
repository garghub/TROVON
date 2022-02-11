static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 ;
F_3 ( V_8 , V_10 ) ;
F_4 ( V_8 , F_5 ( V_2 ) &
V_10 ) ;
V_9 = F_6 ( V_8 , V_3 , V_4 ) ;
F_7 ( V_2 , F_8 ( V_8 ) &
V_11 ) ;
return V_9 ;
}
static int F_9 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
struct V_7 * V_16 )
{
int V_17 = F_10 ( V_16 ) ;
unsigned int V_18 = V_15 -> V_18 ;
T_1 * V_19 = V_15 -> V_19 . V_20 . V_21 ;
T_1 * V_22 = V_15 -> V_22 . V_20 . V_21 ;
T_1 * V_23 = V_15 -> V_23 ;
do {
F_11 ( V_23 , V_19 , V_17 ) ;
F_12 ( V_16 , V_22 , V_23 ) ;
memcpy ( V_23 , V_22 , V_17 ) ;
F_11 ( V_23 , V_19 , V_17 ) ;
V_19 += V_17 ;
V_22 += V_17 ;
} while ( ( V_18 -= V_17 ) >= V_17 );
return V_18 ;
}
static int F_13 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
struct V_7 * V_16 )
{
int V_17 = F_10 ( V_16 ) ;
unsigned int V_18 = V_15 -> V_18 ;
T_1 * V_19 = V_15 -> V_19 . V_20 . V_21 ;
T_1 * V_23 = V_15 -> V_23 ;
T_1 V_24 [ V_17 ] ;
do {
memcpy ( V_24 , V_19 , V_17 ) ;
F_11 ( V_23 , V_19 , V_17 ) ;
F_12 ( V_16 , V_19 , V_23 ) ;
memcpy ( V_23 , V_24 , V_17 ) ;
F_11 ( V_23 , V_19 , V_17 ) ;
V_19 += V_17 ;
} while ( ( V_18 -= V_17 ) >= V_17 );
memcpy ( V_15 -> V_23 , V_23 , V_17 ) ;
return V_18 ;
}
static int F_14 ( struct V_12 * V_13 )
{
struct V_1 * V_16 = F_15 ( V_13 ) ;
struct V_5 * V_6 = F_2 ( V_16 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_14 V_15 ;
unsigned int V_18 ;
int V_9 ;
V_9 = F_16 ( & V_15 , V_13 , false ) ;
while ( ( V_18 = V_15 . V_18 ) ) {
if ( V_15 . V_19 . V_20 . V_21 == V_15 . V_22 . V_20 . V_21 )
V_18 = F_13 ( V_13 , & V_15 ,
V_8 ) ;
else
V_18 = F_9 ( V_13 , & V_15 ,
V_8 ) ;
V_9 = F_17 ( & V_15 , V_18 ) ;
}
return V_9 ;
}
static int F_18 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
struct V_7 * V_16 )
{
int V_17 = F_10 ( V_16 ) ;
unsigned int V_18 = V_15 -> V_18 ;
T_1 * V_19 = V_15 -> V_19 . V_20 . V_21 ;
T_1 * V_22 = V_15 -> V_22 . V_20 . V_21 ;
T_1 * V_23 = V_15 -> V_23 ;
do {
F_19 ( V_16 , V_22 , V_19 ) ;
F_11 ( V_22 , V_23 , V_17 ) ;
memcpy ( V_23 , V_19 , V_17 ) ;
F_11 ( V_23 , V_22 , V_17 ) ;
V_19 += V_17 ;
V_22 += V_17 ;
} while ( ( V_18 -= V_17 ) >= V_17 );
memcpy ( V_15 -> V_23 , V_23 , V_17 ) ;
return V_18 ;
}
static int F_20 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
struct V_7 * V_16 )
{
int V_17 = F_10 ( V_16 ) ;
unsigned int V_18 = V_15 -> V_18 ;
T_1 * V_19 = V_15 -> V_19 . V_20 . V_21 ;
T_1 * V_23 = V_15 -> V_23 ;
T_1 V_24 [ V_17 ] V_25 ( ( F_21 ( F_22 ( V_26 ) ) ) ) ;
do {
memcpy ( V_24 , V_19 , V_17 ) ;
F_19 ( V_16 , V_19 , V_19 ) ;
F_11 ( V_19 , V_23 , V_17 ) ;
memcpy ( V_23 , V_24 , V_17 ) ;
F_11 ( V_23 , V_19 , V_17 ) ;
V_19 += V_17 ;
} while ( ( V_18 -= V_17 ) >= V_17 );
memcpy ( V_15 -> V_23 , V_23 , V_17 ) ;
return V_18 ;
}
static int F_23 ( struct V_12 * V_13 )
{
struct V_1 * V_16 = F_15 ( V_13 ) ;
struct V_5 * V_6 = F_2 ( V_16 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_14 V_15 ;
unsigned int V_18 ;
int V_9 ;
V_9 = F_16 ( & V_15 , V_13 , false ) ;
while ( ( V_18 = V_15 . V_18 ) ) {
if ( V_15 . V_19 . V_20 . V_21 == V_15 . V_22 . V_20 . V_21 )
V_18 = F_20 ( V_13 , & V_15 ,
V_8 ) ;
else
V_18 = F_18 ( V_13 , & V_15 ,
V_8 ) ;
V_9 = F_17 ( & V_15 , V_18 ) ;
}
return V_9 ;
}
static int F_24 ( struct V_1 * V_16 )
{
struct V_27 * V_28 = F_25 ( V_16 ) ;
struct V_29 * V_30 = F_26 ( V_28 ) ;
struct V_5 * V_6 = F_2 ( V_16 ) ;
struct V_7 * V_31 ;
V_31 = F_27 ( V_30 ) ;
if ( F_28 ( V_31 ) )
return F_29 ( V_31 ) ;
V_6 -> V_8 = V_31 ;
return 0 ;
}
static void F_30 ( struct V_1 * V_16 )
{
struct V_5 * V_6 = F_2 ( V_16 ) ;
F_31 ( V_6 -> V_8 ) ;
}
static void F_32 ( struct V_27 * V_28 )
{
F_33 ( F_26 ( V_28 ) ) ;
F_34 ( V_28 ) ;
}
static int F_35 ( struct V_32 * V_33 , struct V_34 * * V_35 )
{
struct V_27 * V_28 ;
struct V_36 * V_37 ;
struct V_29 * V_30 ;
struct V_38 * V_39 ;
int V_9 ;
V_37 = F_36 ( V_35 ) ;
if ( F_28 ( V_37 ) )
return F_29 ( V_37 ) ;
if ( ( ( V_37 -> type ^ V_40 ) & V_37 -> V_41 ) &
~ V_42 )
return - V_43 ;
V_28 = F_37 ( sizeof( * V_28 ) + sizeof( * V_30 ) , V_44 ) ;
if ( ! V_28 )
return - V_45 ;
V_39 = F_38 ( V_35 , V_46 |
( V_37 -> type & V_42 ) ,
V_47 |
( V_37 -> V_41 & V_42 ) ) ;
V_9 = F_29 ( V_39 ) ;
if ( F_28 ( V_39 ) )
goto V_48;
V_30 = F_26 ( V_28 ) ;
V_9 = F_39 ( V_30 , V_39 , F_40 ( V_28 ) ,
V_47 ) ;
F_41 ( V_39 ) ;
if ( V_9 )
goto V_48;
V_9 = F_42 ( F_40 ( V_28 ) , L_1 , V_39 ) ;
if ( V_9 )
goto V_49;
V_28 -> V_39 . V_50 . V_51 = V_39 -> V_51 & V_42 ;
V_28 -> V_39 . V_50 . V_52 = V_39 -> V_52 ;
V_28 -> V_39 . V_50 . V_53 = V_39 -> V_53 ;
V_28 -> V_39 . V_50 . V_54 = V_39 -> V_54 ;
V_28 -> V_39 . V_50 . V_54 |= F_22 ( V_26 ) - 1 ;
V_28 -> V_39 . V_55 = V_39 -> V_53 ;
V_28 -> V_39 . V_56 = V_39 -> V_57 . V_58 ;
V_28 -> V_39 . V_59 = V_39 -> V_57 . V_60 ;
V_28 -> V_39 . V_50 . V_61 = sizeof( struct V_5 ) ;
V_28 -> V_39 . V_62 = F_24 ;
V_28 -> V_39 . exit = F_30 ;
V_28 -> V_39 . V_63 = F_1 ;
V_28 -> V_39 . V_64 = F_14 ;
V_28 -> V_39 . V_65 = F_23 ;
V_28 -> free = F_32 ;
V_9 = F_43 ( V_33 , V_28 ) ;
if ( V_9 )
goto V_49;
V_66:
return V_9 ;
V_49:
F_44 ( V_30 ) ;
V_48:
F_34 ( V_28 ) ;
goto V_66;
}
static int T_2 F_45 ( void )
{
return F_46 ( & V_67 ) ;
}
static void T_3 F_47 ( void )
{
F_48 ( & V_67 ) ;
}
