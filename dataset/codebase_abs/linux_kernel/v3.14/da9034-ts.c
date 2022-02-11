static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 , V_4 ) ;
}
static inline int F_3 ( struct V_1 * V_2 , int V_5 )
{
if ( V_5 )
return F_4 ( V_2 -> V_3 ,
V_6 , V_7 ) ;
else
return F_5 ( V_2 -> V_3 ,
V_6 , V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_8 , V_9 , V_10 ;
int V_11 ;
V_11 = F_7 ( V_2 -> V_3 , V_12 , & V_8 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_7 ( V_2 -> V_3 , V_13 , & V_9 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_7 ( V_2 -> V_3 , V_14 , & V_10 ) ;
if ( V_11 )
return V_11 ;
V_2 -> V_15 = ( ( V_8 << 2 ) & 0x3fc ) | ( V_10 & 0x3 ) ;
V_2 -> V_16 = ( ( V_9 << 2 ) & 0x3fc ) | ( ( V_10 & 0xc ) >> 2 ) ;
return 0 ;
}
static inline int F_8 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_3 ,
V_6 , V_17 ) ;
}
static inline int F_9 ( struct V_1 * V_2 )
{
return F_5 ( V_2 -> V_3 ,
V_6 , V_17 ) ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
int V_18 = V_2 -> V_15 ;
int V_19 = V_2 -> V_16 ;
V_18 &= 0xfff ;
if ( V_2 -> V_20 )
V_18 = 1024 - V_18 ;
V_19 &= 0xfff ;
if ( V_2 -> V_21 )
V_19 = 1024 - V_19 ;
F_11 ( V_2 -> V_22 , V_23 , V_18 ) ;
F_11 ( V_2 -> V_22 , V_24 , V_19 ) ;
F_12 ( V_2 -> V_22 , V_25 , 1 ) ;
F_13 ( V_2 -> V_22 ) ;
}
static inline void F_14 ( struct V_1 * V_2 )
{
F_12 ( V_2 -> V_22 , V_25 , 0 ) ;
F_13 ( V_2 -> V_22 ) ;
}
static void F_15 ( struct V_1 * V_2 , int V_26 )
{
int V_27 ;
switch ( V_2 -> V_28 ) {
case V_29 :
if ( V_26 != V_30 )
break;
V_27 = F_8 ( V_2 ) ;
if ( V_27 )
goto V_31;
V_2 -> V_28 = V_32 ;
break;
case V_32 :
if ( V_26 != V_33 )
break;
V_27 = F_6 ( V_2 ) ;
if ( V_27 )
goto V_31;
V_27 = F_9 ( V_2 ) ;
if ( V_27 )
goto V_31;
V_2 -> V_28 = V_34 ;
F_16 ( 1 ) ;
F_15 ( V_2 ,
F_1 ( V_2 ) ? V_30 :
V_35 ) ;
break;
case V_34 :
if ( V_26 == V_30 ) {
F_10 ( V_2 ) ;
F_17 ( & V_2 -> V_36 ,
F_18 ( V_2 -> V_37 ) ) ;
V_2 -> V_28 = V_38 ;
}
if ( V_26 == V_35 ) {
F_14 ( V_2 ) ;
V_2 -> V_28 = V_29 ;
}
break;
case V_38 :
if ( V_26 != V_39 )
break;
if ( F_1 ( V_2 ) ) {
F_8 ( V_2 ) ;
V_2 -> V_28 = V_32 ;
} else {
F_14 ( V_2 ) ;
V_2 -> V_28 = V_29 ;
}
break;
}
return;
V_31:
V_2 -> V_28 = V_29 ;
F_9 ( V_2 ) ;
F_3 ( V_2 , 1 ) ;
}
static void F_19 ( struct V_40 * V_41 )
{
struct V_1 * V_2 =
F_20 ( V_41 , struct V_1 , V_36 . V_41 ) ;
F_15 ( V_2 , V_39 ) ;
}
static int F_21 ( struct V_42 * V_43 ,
unsigned long V_26 , void * V_44 )
{
struct V_1 * V_2 =
F_20 ( V_43 , struct V_1 , V_45 ) ;
if ( V_26 & V_46 )
F_15 ( V_2 , V_33 ) ;
if ( ( V_26 & V_47 ) && V_2 -> V_28 == V_29 )
F_15 ( V_2 , V_30 ) ;
return 0 ;
}
static int F_22 ( struct V_22 * V_48 )
{
struct V_1 * V_2 = F_23 ( V_48 ) ;
int V_11 ;
V_11 = F_24 ( V_2 -> V_3 , & V_2 -> V_45 ,
V_47 | V_46 ) ;
if ( V_11 )
return - V_49 ;
V_11 = F_4 ( V_2 -> V_3 ,
V_50 , V_51 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_25 ( V_2 -> V_3 , V_52 , 0x1b ) ;
if ( V_11 )
return V_11 ;
V_11 = F_25 ( V_2 -> V_3 , V_53 , 0x00 ) ;
if ( V_11 )
return V_11 ;
V_2 -> V_28 = V_29 ;
F_3 ( V_2 , 1 ) ;
return 0 ;
}
static void F_26 ( struct V_22 * V_48 )
{
struct V_1 * V_2 = F_23 ( V_48 ) ;
F_27 ( V_2 -> V_3 , & V_2 -> V_45 ,
V_47 | V_46 ) ;
F_28 ( & V_2 -> V_36 ) ;
V_2 -> V_28 = V_29 ;
F_9 ( V_2 ) ;
F_3 ( V_2 , 0 ) ;
F_5 ( V_2 -> V_3 ,
V_50 , V_51 ) ;
}
static int F_29 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = F_30 ( & V_55 -> V_48 ) ;
struct V_1 * V_2 ;
struct V_22 * V_22 ;
int V_11 ;
V_2 = F_31 ( sizeof( struct V_1 ) , V_58 ) ;
if ( V_2 == NULL ) {
F_32 ( & V_55 -> V_48 , L_1 ) ;
return - V_59 ;
}
V_2 -> V_3 = V_55 -> V_48 . V_60 ;
if ( V_57 ) {
V_2 -> V_37 = V_57 -> V_37 ;
V_2 -> V_20 = V_57 -> V_20 ;
V_2 -> V_21 = V_57 -> V_21 ;
} else
V_2 -> V_37 = 10 ;
F_33 ( & V_2 -> V_36 , F_19 ) ;
V_2 -> V_45 . V_61 = F_21 ;
V_22 = F_34 () ;
if ( ! V_22 ) {
F_32 ( & V_55 -> V_48 , L_2 ) ;
V_11 = - V_59 ;
goto V_62;
}
V_22 -> V_63 = V_55 -> V_63 ;
V_22 -> V_64 = F_22 ;
V_22 -> V_65 = F_26 ;
V_22 -> V_48 . V_60 = & V_55 -> V_48 ;
F_35 ( V_66 , V_22 -> V_67 ) ;
F_35 ( V_23 , V_22 -> V_68 ) ;
F_35 ( V_24 , V_22 -> V_68 ) ;
F_36 ( V_22 , V_23 , 0 , 1023 , 0 , 0 ) ;
F_36 ( V_22 , V_24 , 0 , 1023 , 0 , 0 ) ;
F_35 ( V_69 , V_22 -> V_67 ) ;
F_35 ( V_25 , V_22 -> V_70 ) ;
V_2 -> V_22 = V_22 ;
F_37 ( V_22 , V_2 ) ;
V_11 = F_38 ( V_22 ) ;
if ( V_11 )
goto V_71;
F_39 ( V_55 , V_2 ) ;
return 0 ;
V_71:
F_40 ( V_22 ) ;
V_62:
F_41 ( V_2 ) ;
return V_11 ;
}
static int F_42 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_43 ( V_55 ) ;
F_44 ( V_2 -> V_22 ) ;
F_41 ( V_2 ) ;
return 0 ;
}
