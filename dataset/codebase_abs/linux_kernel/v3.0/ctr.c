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
static void F_9 ( struct V_12 * V_13 ,
struct V_7 * V_14 )
{
unsigned int V_15 = F_10 ( V_14 ) ;
unsigned long V_16 = F_11 ( V_14 ) ;
T_1 * V_17 = V_13 -> V_18 ;
T_1 V_19 [ V_15 + V_16 ] ;
T_1 * V_20 = F_12 ( V_19 + 0 , V_16 + 1 ) ;
T_1 * V_21 = V_13 -> V_21 . V_22 . V_23 ;
T_1 * V_24 = V_13 -> V_24 . V_22 . V_23 ;
unsigned int V_25 = V_13 -> V_25 ;
F_13 ( V_14 , V_20 , V_17 ) ;
F_14 ( V_20 , V_21 , V_25 ) ;
memcpy ( V_24 , V_20 , V_25 ) ;
F_15 ( V_17 , V_15 ) ;
}
static int F_16 ( struct V_12 * V_13 ,
struct V_7 * V_14 )
{
void (* F_17)( struct V_1 * , T_1 * , const T_1 * ) =
F_18 ( V_14 ) -> V_26 ;
unsigned int V_15 = F_10 ( V_14 ) ;
T_1 * V_17 = V_13 -> V_18 ;
T_1 * V_21 = V_13 -> V_21 . V_22 . V_23 ;
T_1 * V_24 = V_13 -> V_24 . V_22 . V_23 ;
unsigned int V_25 = V_13 -> V_25 ;
do {
F_17 ( F_19 ( V_14 ) , V_24 , V_17 ) ;
F_14 ( V_24 , V_21 , V_15 ) ;
F_15 ( V_17 , V_15 ) ;
V_21 += V_15 ;
V_24 += V_15 ;
} while ( ( V_25 -= V_15 ) >= V_15 );
return V_25 ;
}
static int F_20 ( struct V_12 * V_13 ,
struct V_7 * V_14 )
{
void (* F_17)( struct V_1 * , T_1 * , const T_1 * ) =
F_18 ( V_14 ) -> V_26 ;
unsigned int V_15 = F_10 ( V_14 ) ;
unsigned long V_16 = F_11 ( V_14 ) ;
unsigned int V_25 = V_13 -> V_25 ;
T_1 * V_17 = V_13 -> V_18 ;
T_1 * V_21 = V_13 -> V_21 . V_22 . V_23 ;
T_1 V_19 [ V_15 + V_16 ] ;
T_1 * V_20 = F_12 ( V_19 + 0 , V_16 + 1 ) ;
do {
F_17 ( F_19 ( V_14 ) , V_20 , V_17 ) ;
F_14 ( V_21 , V_20 , V_15 ) ;
F_15 ( V_17 , V_15 ) ;
V_21 += V_15 ;
} while ( ( V_25 -= V_15 ) >= V_15 );
return V_25 ;
}
static int F_21 ( struct V_27 * V_28 ,
struct V_29 * V_24 , struct V_29 * V_21 ,
unsigned int V_25 )
{
struct V_12 V_13 ;
struct V_30 * V_14 = V_28 -> V_14 ;
struct V_5 * V_6 = F_22 ( V_14 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_15 = F_10 ( V_8 ) ;
int V_9 ;
F_23 ( & V_13 , V_24 , V_21 , V_25 ) ;
V_9 = F_24 ( V_28 , & V_13 , V_15 ) ;
while ( V_13 . V_25 >= V_15 ) {
if ( V_13 . V_21 . V_22 . V_23 == V_13 . V_24 . V_22 . V_23 )
V_25 = F_20 ( & V_13 , V_8 ) ;
else
V_25 = F_16 ( & V_13 , V_8 ) ;
V_9 = F_25 ( V_28 , & V_13 , V_25 ) ;
}
if ( V_13 . V_25 ) {
F_9 ( & V_13 , V_8 ) ;
V_9 = F_25 ( V_28 , & V_13 , 0 ) ;
}
return V_9 ;
}
static int F_26 ( struct V_1 * V_14 )
{
struct V_31 * V_32 = ( void * ) V_14 -> V_33 ;
struct V_34 * V_35 = F_27 ( V_32 ) ;
struct V_5 * V_6 = F_2 ( V_14 ) ;
struct V_7 * V_36 ;
V_36 = F_28 ( V_35 ) ;
if ( F_29 ( V_36 ) )
return F_30 ( V_36 ) ;
V_6 -> V_8 = V_36 ;
return 0 ;
}
static void F_31 ( struct V_1 * V_14 )
{
struct V_5 * V_6 = F_2 ( V_14 ) ;
F_32 ( V_6 -> V_8 ) ;
}
static struct V_31 * F_33 ( struct V_37 * * V_38 )
{
struct V_31 * V_32 ;
struct V_39 * V_40 ;
int V_9 ;
V_9 = F_34 ( V_38 , V_41 ) ;
if ( V_9 )
return F_35 ( V_9 ) ;
V_40 = F_36 ( V_38 [ 1 ] , V_42 ,
V_43 ) ;
if ( F_29 ( V_40 ) )
return F_37 ( V_40 ) ;
V_9 = - V_44 ;
if ( V_40 -> V_45 < 4 )
goto V_46;
if ( V_40 -> V_45 % 4 )
goto V_46;
V_32 = F_38 ( L_1 , V_40 ) ;
if ( F_29 ( V_32 ) )
goto V_47;
V_32 -> V_40 . V_48 = V_41 ;
V_32 -> V_40 . V_49 = V_40 -> V_49 ;
V_32 -> V_40 . V_45 = 1 ;
V_32 -> V_40 . V_50 = V_40 -> V_50 | ( F_39 ( V_51 ) - 1 ) ;
V_32 -> V_40 . V_52 = & V_53 ;
V_32 -> V_40 . V_54 . V_55 = V_40 -> V_45 ;
V_32 -> V_40 . V_54 . V_56 = V_40 -> V_57 . V_58 ;
V_32 -> V_40 . V_54 . V_59 = V_40 -> V_57 . V_60 ;
V_32 -> V_40 . V_61 = sizeof( struct V_5 ) ;
V_32 -> V_40 . V_62 = F_26 ;
V_32 -> V_40 . V_63 = F_31 ;
V_32 -> V_40 . V_54 . V_64 = F_1 ;
V_32 -> V_40 . V_54 . V_65 = F_21 ;
V_32 -> V_40 . V_54 . V_66 = F_21 ;
V_32 -> V_40 . V_54 . V_67 = L_2 ;
V_47:
F_40 ( V_40 ) ;
return V_32 ;
V_46:
V_32 = F_35 ( V_9 ) ;
goto V_47;
}
static void F_41 ( struct V_31 * V_32 )
{
F_42 ( F_27 ( V_32 ) ) ;
F_43 ( V_32 ) ;
}
static int F_44 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_68 * V_6 = F_2 ( V_2 ) ;
struct V_30 * V_8 = V_6 -> V_8 ;
int V_9 ;
if ( V_4 < V_69 )
return - V_44 ;
memcpy ( V_6 -> V_70 , V_3 + ( V_4 - V_69 ) ,
V_69 ) ;
V_4 -= V_69 ;
F_45 ( V_8 , V_10 ) ;
F_46 ( V_8 , F_5 ( V_2 ) &
V_10 ) ;
V_9 = F_47 ( V_8 , V_3 , V_4 ) ;
F_7 ( V_2 , F_48 ( V_8 ) &
V_11 ) ;
return V_9 ;
}
static int F_49 ( struct V_27 * V_28 ,
struct V_29 * V_24 ,
struct V_29 * V_21 , unsigned int V_25 )
{
struct V_30 * V_14 = V_28 -> V_14 ;
struct V_68 * V_6 = F_22 ( V_14 ) ;
struct V_30 * V_8 = V_6 -> V_8 ;
unsigned long V_16 = F_50 ( V_14 ) ;
T_1 V_71 [ V_72 + V_16 ] ;
T_1 * V_18 = F_12 ( V_71 + 0 , V_16 + 1 ) ;
T_1 * V_73 = V_28 -> V_73 ;
int V_9 ;
memcpy ( V_18 , V_6 -> V_70 , V_69 ) ;
memcpy ( V_18 + V_69 , V_73 , V_74 ) ;
* ( V_75 * ) ( V_18 + V_69 + V_74 ) =
F_51 ( 1 ) ;
V_28 -> V_14 = V_8 ;
V_28 -> V_73 = V_18 ;
V_9 = F_52 ( V_28 , V_24 , V_21 , V_25 ) ;
V_28 -> V_14 = V_14 ;
V_28 -> V_73 = V_73 ;
return V_9 ;
}
static int F_53 ( struct V_1 * V_14 )
{
struct V_31 * V_32 = ( void * ) V_14 -> V_33 ;
struct V_34 * V_35 = F_27 ( V_32 ) ;
struct V_68 * V_6 = F_2 ( V_14 ) ;
struct V_30 * V_36 ;
V_36 = F_54 ( V_35 ) ;
if ( F_29 ( V_36 ) )
return F_30 ( V_36 ) ;
V_6 -> V_8 = V_36 ;
return 0 ;
}
static void F_55 ( struct V_1 * V_14 )
{
struct V_68 * V_6 = F_2 ( V_14 ) ;
F_56 ( V_6 -> V_8 ) ;
}
static struct V_31 * F_57 ( struct V_37 * * V_38 )
{
struct V_31 * V_32 ;
struct V_39 * V_40 ;
int V_9 ;
V_9 = F_34 ( V_38 , V_41 ) ;
if ( V_9 )
return F_35 ( V_9 ) ;
V_40 = F_36 ( V_38 [ 1 ] , V_41 ,
V_43 ) ;
V_9 = F_30 ( V_40 ) ;
if ( F_29 ( V_40 ) )
return F_35 ( V_9 ) ;
V_9 = - V_44 ;
if ( V_40 -> V_54 . V_55 != V_72 )
goto V_46;
if ( V_40 -> V_45 != 1 )
goto V_46;
V_32 = F_38 ( L_3 , V_40 ) ;
if ( F_29 ( V_32 ) )
goto V_47;
V_32 -> V_40 . V_48 = V_41 ;
V_32 -> V_40 . V_49 = V_40 -> V_49 ;
V_32 -> V_40 . V_45 = 1 ;
V_32 -> V_40 . V_50 = V_40 -> V_50 ;
V_32 -> V_40 . V_52 = & V_53 ;
V_32 -> V_40 . V_54 . V_55 = V_74 ;
V_32 -> V_40 . V_54 . V_56 = V_40 -> V_54 . V_56
+ V_69 ;
V_32 -> V_40 . V_54 . V_59 = V_40 -> V_54 . V_59
+ V_69 ;
V_32 -> V_40 . V_54 . V_67 = L_4 ;
V_32 -> V_40 . V_61 = sizeof( struct V_68 ) ;
V_32 -> V_40 . V_62 = F_53 ;
V_32 -> V_40 . V_63 = F_55 ;
V_32 -> V_40 . V_54 . V_64 = F_44 ;
V_32 -> V_40 . V_54 . V_65 = F_49 ;
V_32 -> V_40 . V_54 . V_66 = F_49 ;
V_47:
F_40 ( V_40 ) ;
return V_32 ;
V_46:
V_32 = F_35 ( V_9 ) ;
goto V_47;
}
static int T_2 F_58 ( void )
{
int V_9 ;
V_9 = F_59 ( & V_76 ) ;
if ( V_9 )
goto V_47;
V_9 = F_59 ( & V_77 ) ;
if ( V_9 )
goto V_78;
V_47:
return V_9 ;
V_78:
F_60 ( & V_76 ) ;
goto V_47;
}
static void T_3 F_61 ( void )
{
F_60 ( & V_77 ) ;
F_60 ( & V_76 ) ;
}
