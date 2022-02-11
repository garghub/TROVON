static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned long V_5 ;
F_2 ( V_4 -> V_6 , V_5 ) ;
F_3 ( V_4 ) ;
F_4 ( V_4 -> V_6 , V_5 ) ;
return V_7 ;
}
static inline
void F_5 ( struct V_8 * V_9 , struct V_10 * V_11 , int V_12 )
{
unsigned long V_13 = V_11 -> V_14 . V_15 ;
void * V_16 = V_11 -> V_14 . V_17 ;
T_2 V_18 ;
unsigned long V_19 ;
struct V_20 * V_21 ;
V_18 = F_6 ( V_9 -> V_22 , V_16 , V_13 , F_7 ( V_12 ) ) ;
V_11 -> V_14 . V_23 = V_18 ;
V_21 = V_9 -> V_24 ;
while ( V_13 ) {
V_19 = V_13 > 8192 ? 8192 : V_13 ;
V_21 -> V_25 . V_26 = V_18 ;
V_21 -> V_25 . V_27 = V_19 ;
V_21 ++ ;
V_13 -= V_19 ;
V_18 += V_19 ;
}
V_21 -> V_25 . V_26 = 0 ;
V_21 -> V_25 . V_27 = V_28 ;
F_8 ( V_9 -> V_22 , V_9 -> V_24 ,
( unsigned long ) ( V_21 + 1 ) - ( unsigned long ) V_9 -> V_24 ,
V_29 ) ;
}
static int F_9 ( struct V_10 * V_11 , int V_30 )
{
struct V_8 * V_31 = F_10 ( V_11 -> V_32 -> V_4 ) ;
struct V_33 * V_34 =
(struct V_33 * ) V_11 -> V_32 -> V_4 -> V_35 ;
F_11 ( L_1 , V_30 , V_31 -> V_24 ) ;
V_31 -> V_36 . V_37 = V_30 ;
if ( V_11 -> V_14 . V_17 == NULL || V_11 -> V_14 . V_15 == 0 )
return 1 ;
F_5 ( V_31 , V_11 , V_30 ) ;
F_11 ( L_2 ) ;
V_34 -> V_38 = V_31 -> V_39 ;
if ( V_30 )
V_34 -> V_40 = V_41 ;
else
V_34 -> V_40 = V_41 | V_42 ;
return 0 ;
}
static void F_12 ( struct V_3 * V_43 , struct V_10 * V_44 ,
int V_45 )
{
struct V_8 * V_31 = F_10 ( V_43 ) ;
struct V_33 * V_34 ;
if ( ! V_44 )
return;
if ( V_44 -> V_14 . V_17 == NULL || V_44 -> V_14 . V_15 == 0 )
return;
V_34 = (struct V_33 * ) V_44 -> V_32 -> V_4 -> V_35 ;
F_11 ( L_3 , V_45 ) ;
if ( V_31 -> V_36 . V_37 ) {
V_34 -> V_40 |= V_46 ;
while ( V_34 -> V_40 & V_41 )
F_13 () ;
}
V_34 -> V_40 = 0 ;
F_14 ( V_31 -> V_22 , V_44 -> V_14 . V_23 ,
V_44 -> V_14 . V_15 ,
F_7 ( V_31 -> V_36 . V_37 ) ) ;
F_11 ( L_4 ) ;
}
void F_15 ( unsigned long V_35 )
{
struct V_33 * V_34 = (struct V_33 * ) V_35 ;
V_34 -> V_40 = V_47 ;
F_16 ( 50 ) ;
V_34 -> V_40 = 0 ;
}
static inline void F_17 ( struct V_8 * V_31 )
{
struct V_20 * V_21 = (struct V_20 * ) V_31 -> V_24 ;
T_2 V_39 = V_31 -> V_39 ;
unsigned long V_48 , V_49 ;
V_48 = ( unsigned long ) V_21 ;
V_49 = V_48 + V_50 ;
while ( V_48 < V_49 ) {
V_21 -> V_25 . V_51 = ( V_52 ) ( V_39 + sizeof( struct V_20 ) ) ;
V_21 -> V_25 . V_27 = V_28 ;
V_21 ++ ;
V_39 += sizeof( struct V_20 ) ;
V_48 += sizeof( struct V_20 ) ;
} ;
V_21 -- ;
V_21 -> V_25 . V_51 = V_31 -> V_39 ;
}
static int F_18 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = V_54 -> V_22 . V_57 ;
unsigned char * V_58 = V_56 -> V_58 ;
struct V_33 * V_34 = V_56 -> V_34 ;
struct V_8 * V_31 ;
struct V_3 * V_4 ;
T_3 V_59 ;
unsigned int V_60 = V_56 -> V_60 ;
unsigned int V_1 = V_56 -> V_1 ;
int V_61 ;
V_4 = F_19 ( & V_62 , sizeof( struct V_8 ) ) ;
if ( ! V_4 ) {
V_61 = - V_63 ;
goto V_64;
}
V_4 -> V_35 = ( unsigned long ) V_34 ;
V_4 -> V_1 = V_1 ;
V_31 = F_10 ( V_4 ) ;
V_31 -> V_22 = & V_54 -> V_22 ;
V_31 -> V_24 = F_20 ( & V_54 -> V_22 , V_50 , & V_31 -> V_39 ,
V_65 , V_66 ) ;
if ( ! V_31 -> V_24 ) {
F_21 ( V_67 L_5
L_6 , V_60 ) ;
V_61 = - V_63 ;
goto V_68;
}
F_17 ( V_31 ) ;
V_59 . V_69 = V_58 + 3 ;
V_59 . V_70 = V_58 + 7 ;
V_31 -> V_36 . V_71 = 0 ;
V_31 -> V_36 . V_72 = 1 ;
V_31 -> V_36 . V_73 = V_74 ;
F_22 ( V_4 , V_59 , F_9 , F_12 , F_23 ( 20 ) ) ;
V_61 = F_24 ( V_1 , F_1 , 0 , L_7 , V_4 ) ;
if ( V_61 ) {
F_21 ( V_67 L_8
L_9 , V_1 , V_60 ) ;
goto V_75;
}
F_25 ( V_54 , V_4 ) ;
V_61 = F_26 ( V_4 , NULL ) ;
if ( V_61 )
goto V_76;
F_27 ( V_4 ) ;
return 0 ;
V_76:
F_28 ( V_1 , V_4 ) ;
V_75:
F_29 ( & V_54 -> V_22 , V_50 , V_31 -> V_24 , V_31 -> V_39 ,
V_66 ) ;
V_68:
F_30 ( V_4 ) ;
V_64:
return V_61 ;
}
static int F_31 ( struct V_53 * V_54 )
{
struct V_3 * V_4 = F_32 ( V_54 ) ;
struct V_8 * V_31 = (struct V_8 * ) V_4 -> V_77 ;
struct V_55 * V_56 = V_54 -> V_22 . V_57 ;
F_33 ( V_4 ) ;
F_28 ( V_56 -> V_1 , V_4 ) ;
F_29 ( & V_54 -> V_22 , V_50 , V_31 -> V_24 , V_31 -> V_39 ,
V_66 ) ;
F_30 ( V_4 ) ;
return 0 ;
}
static int T_4 F_34 ( void )
{
return F_35 ( & V_78 ) ;
}
static void T_5 F_36 ( void )
{
return F_37 ( & V_78 ) ;
}
