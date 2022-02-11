static int F_1 ( struct V_1 * V_2 , unsigned char * V_3 ,
int V_4 )
{
for (; V_4 > 0 ; V_4 -- , V_3 ++ )
* V_3 = F_2 ( F_3 ( V_2 , V_5 ) ) ;
return F_4 ( F_3 ( V_2 , V_6 ) ) ;
}
static inline void F_5 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
int V_9 = V_8 -> V_4 ;
char * V_10 = V_8 -> V_11 ;
F_6 ( V_8 -> V_4 , F_3 ( V_2 , V_12 ) ) ;
for (; V_9 ; V_10 ++ , V_9 -- )
F_7 ( * V_10 , F_3 ( V_2 , V_13 ) ) ;
V_2 -> V_14 . V_15 ++ ;
V_2 -> V_14 . V_16 += V_8 -> V_4 ;
F_8 ( V_8 ) ;
}
static int F_9 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
F_5 ( V_2 , V_8 ) ;
return V_17 ;
}
static inline T_1 F_11 ( struct V_1 * V_2 , T_2 V_4 )
{
struct V_7 * V_8 ;
if ( ! V_4 )
return V_4 ;
V_8 = F_12 ( V_4 + V_18 ) ;
if ( ! V_8 ) {
V_2 -> V_14 . V_19 ++ ;
return - V_20 ;
}
F_13 ( V_8 , V_18 ) ;
if ( F_1 ( V_2 , F_14 ( V_8 , V_4 ) , V_4 ) )
return - V_21 ;
V_8 -> V_22 = F_15 ( V_8 , V_2 ) ;
V_8 -> V_23 = V_24 ;
F_16 ( V_8 ) ;
V_2 -> V_14 . V_25 ++ ;
V_2 -> V_14 . V_26 += V_4 ;
return V_4 ;
}
static T_3 F_17 ( int V_27 , void * V_28 )
{
struct V_1 * V_2 = V_28 ;
T_4 V_29 ;
T_3 V_30 = V_31 ;
if ( V_27 != V_2 -> V_27 )
goto V_32;
V_29 = F_4 ( F_3 ( V_2 , V_33 ) ) ;
if ( V_29 & V_34 ) {
F_6 ( 0 , F_3 ( V_2 , V_33 ) ) ;
V_30 = V_35 ;
} else if ( V_29 & V_36 ) {
V_2 -> V_14 . V_15 ++ ;
F_18 ( V_2 ) ;
F_6 ( V_36 ,
F_3 ( V_2 , V_33 ) ) ;
V_30 = V_35 ;
} else if ( V_29 & V_37 ) {
F_11 ( V_2 , F_4 ( F_3 ( V_2 , V_6 ) ) ) ;
F_6 ( V_37 , F_3 ( V_2 , V_33 ) ) ;
V_30 = V_35 ;
}
return V_30 ;
V_32:
F_19 ( V_38 L_1 ,
V_2 -> V_39 , V_40 , V_27 ) ;
return V_30 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_41 ;
V_41 = F_21 ( V_2 -> V_27 , F_17 ,
V_42 , V_2 -> V_39 , ( void * ) V_2 ) ;
if ( V_41 ) {
F_22 ( V_2 -> V_43 , sizeof( struct V_44 ) ) ;
return V_41 ;
}
F_23 ( V_2 ) ;
F_6 ( V_34 , F_3 ( V_2 , V_33 ) ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
F_25 ( V_2 -> V_27 , V_2 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
}
static int T_5 F_27 ( struct V_45 * V_2 )
{
struct V_1 * V_46 ;
int V_41 ;
V_46 = F_28 ( 0 ) ;
if ( ! V_46 ) {
V_41 = - V_20 ;
goto V_47;
}
F_29 ( V_2 , V_46 ) ;
V_46 -> V_48 = & V_49 ;
V_46 -> V_43 = 0x4200 ;
V_46 -> V_27 = V_50 + V_51 +
F_4 ( F_3 ( V_46 , V_52 ) ) ;
if ( ! F_30 ( V_46 -> V_43 , sizeof( struct V_44 ) ,
L_2 ) ) {
V_41 = - V_53 ;
goto V_54;
}
F_31 ( V_46 -> V_55 ) ;
V_41 = F_32 ( V_46 ) ;
if ( V_41 ) {
F_19 ( V_56 L_3 ) ;
goto V_57;
}
return 0 ;
V_57:
F_22 ( V_46 -> V_43 , sizeof( struct V_44 ) ) ;
V_54:
F_33 ( V_46 ) ;
V_47:
return V_41 ;
}
static int T_6 F_34 ( struct V_45 * V_58 )
{
struct V_1 * V_2 = F_35 ( V_58 ) ;
F_36 ( V_2 ) ;
F_22 ( V_2 -> V_43 , sizeof( struct V_44 ) ) ;
F_33 ( V_2 ) ;
F_29 ( V_58 , NULL ) ;
return 0 ;
}
static int T_7 F_37 ( void )
{
int V_41 ;
F_19 ( V_38 L_4
L_5 , V_59 ) ;
V_41 = F_38 ( & V_60 ) ;
if ( V_41 )
F_19 ( V_56 L_6 ) ;
return V_41 ;
}
static void T_8 F_39 ( void )
{
F_40 ( & V_60 ) ;
}
