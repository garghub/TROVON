static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 , V_5 ) ;
}
static inline unsigned int F_4 ( void T_1 * V_6 , unsigned int V_7 )
{
return F_5 ( V_6 + V_7 ) ;
}
static inline void F_6 ( void T_1 * V_6 , unsigned int V_7 , unsigned long V_8 )
{
F_7 ( V_8 , V_6 + V_7 ) ;
}
static T_2 F_8 ( struct V_2 * V_9 )
{
struct V_1 * V_10 = F_1 ( V_9 ) ;
unsigned long V_11 ;
T_3 V_12 ;
T_3 V_13 ;
F_9 ( V_11 ) ;
V_12 = V_10 -> V_14 ;
V_13 = F_4 ( V_10 -> V_6 , V_15 ) ;
F_10 ( V_11 ) ;
V_12 += F_11 ( V_13 ) * V_10 -> V_16 ;
V_12 += F_12 ( V_13 ) ;
return V_12 ;
}
static void
F_13 ( enum V_17 V_18 , struct V_4 * V_19 )
{
struct V_1 * V_10 = F_3 ( V_19 ) ;
switch ( V_18 ) {
case V_20 :
V_10 -> V_14 += V_10 -> V_16 * F_11 ( F_4 ( V_10 -> V_6 , V_21 ) ) ;
F_6 ( V_10 -> V_6 , V_22 ,
( V_10 -> V_16 - 1 ) | V_23 | V_24 ) ;
break;
case V_25 :
F_14 () ;
case V_26 :
case V_27 :
F_6 ( V_10 -> V_6 , V_22 ,
( V_10 -> V_16 - 1 ) | V_23 ) ;
break;
case V_28 :
break;
}
}
static void F_15 ( struct V_4 * V_29 )
{
struct V_1 * V_10 = F_3 ( V_29 ) ;
F_6 ( V_10 -> V_6 , V_22 , 0 ) ;
}
static void F_16 ( struct V_1 * V_10 )
{
F_6 ( V_10 -> V_6 , V_22 , 0 ) ;
while ( F_12 ( F_4 ( V_10 -> V_6 , V_21 ) ) != 0 )
F_17 () ;
F_6 ( V_10 -> V_6 , V_22 ,
( V_10 -> V_16 - 1 ) | V_23 ) ;
}
static void F_18 ( struct V_4 * V_29 )
{
struct V_1 * V_10 = F_3 ( V_29 ) ;
F_16 ( V_10 ) ;
}
static T_4 F_19 ( int V_30 , void * V_31 )
{
struct V_1 * V_10 = V_31 ;
F_20 ( ! F_21 () ) ;
if ( ( V_10 -> V_5 . V_18 == V_20 ) &&
( F_4 ( V_10 -> V_6 , V_32 ) & V_33 ) ) {
unsigned V_34 ;
V_34 = F_11 ( F_4 ( V_10 -> V_6 , V_21 ) ) ;
do {
V_10 -> V_14 += V_10 -> V_16 ;
V_10 -> V_5 . V_35 ( & V_10 -> V_5 ) ;
V_34 -- ;
} while ( V_34 );
return V_36 ;
}
return V_37 ;
}
static void T_5 F_22 ( struct V_1 * V_10 )
{
unsigned long V_38 ;
unsigned V_39 ;
int V_40 ;
V_38 = F_23 ( V_10 -> V_41 ) / 16 ;
V_10 -> V_16 = F_24 ( V_38 , V_42 ) ;
F_25 ( ( ( V_10 -> V_16 - 1 ) & ~ V_43 ) != 0 ) ;
F_16 ( V_10 ) ;
V_39 = 12 + F_26 ( V_10 -> V_16 ) ;
V_10 -> V_3 . V_44 = F_27 ( V_39 ) ;
V_10 -> V_3 . V_45 = L_1 ;
V_10 -> V_3 . V_46 = 175 ;
V_10 -> V_3 . V_47 = F_8 ,
V_10 -> V_3 . V_11 = V_48 ,
F_28 ( & V_10 -> V_3 , V_38 ) ;
V_40 = F_29 ( V_10 -> V_30 , F_19 ,
V_49 | V_50 | V_51 ,
L_2 , V_10 ) ;
if ( V_40 )
F_30 ( F_31 ( L_3 ) ) ;
V_10 -> V_5 . V_45 = L_1 ;
V_10 -> V_5 . V_52 = V_53 ;
V_10 -> V_5 . V_54 = 32 ;
V_10 -> V_5 . V_55 = F_32 ( V_38 , V_56 , V_10 -> V_5 . V_54 ) ;
V_10 -> V_5 . V_46 = 100 ;
V_10 -> V_5 . V_57 = F_33 ( 0 ) ;
V_10 -> V_5 . V_58 = F_13 ;
V_10 -> V_5 . V_59 = F_18 ;
V_10 -> V_5 . V_60 = F_15 ;
F_34 ( & V_10 -> V_5 ) ;
}
static void T_5 F_35 ( struct V_61 * V_62 )
{
struct V_1 * V_10 ;
V_10 = F_36 ( sizeof( * V_10 ) , V_63 ) ;
if ( ! V_10 )
F_30 ( F_31 ( L_4 ) ) ;
V_10 -> V_6 = F_37 ( V_62 , 0 ) ;
if ( ! V_10 -> V_6 )
F_30 ( F_31 ( L_5 ) ) ;
V_10 -> V_41 = F_38 ( V_62 , 0 ) ;
if ( F_39 ( V_10 -> V_41 ) )
V_10 -> V_41 = F_40 ( NULL , L_6 ) ;
if ( F_39 ( V_10 -> V_41 ) )
F_30 ( F_31 ( L_7 ) ) ;
V_10 -> V_30 = F_41 ( V_62 , 0 ) ;
if ( ! V_10 -> V_30 )
F_30 ( F_31 ( L_8 ) ) ;
F_22 ( V_10 ) ;
}
