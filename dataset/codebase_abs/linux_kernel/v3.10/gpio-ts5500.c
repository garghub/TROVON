static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static inline void F_3 ( T_1 V_4 , T_1 V_5 )
{
T_1 V_6 = F_4 ( V_5 ) ;
V_6 |= V_4 ;
F_5 ( V_6 , V_5 ) ;
}
static inline void F_6 ( T_1 V_4 , T_1 V_5 )
{
T_1 V_6 = F_4 ( V_5 ) ;
V_6 &= ~ V_4 ;
F_5 ( V_6 , V_5 ) ;
}
static int F_7 ( struct V_2 * V_3 , unsigned V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
const struct V_9 line = V_8 -> V_10 [ V_7 ] ;
unsigned long V_11 ;
if ( line . V_12 )
return - V_13 ;
if ( line . V_14 )
return 0 ;
F_8 ( & V_8 -> V_15 , V_11 ) ;
F_6 ( line . V_16 , line . V_17 ) ;
F_9 ( & V_8 -> V_15 , V_11 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , unsigned V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
const struct V_9 line = V_8 -> V_10 [ V_7 ] ;
return ! ! ( F_4 ( line . V_18 ) & line . V_19 ) ;
}
static int F_11 ( struct V_2 * V_3 , unsigned V_7 , int V_6 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
const struct V_9 line = V_8 -> V_10 [ V_7 ] ;
unsigned long V_11 ;
if ( line . V_14 )
return - V_13 ;
F_8 ( & V_8 -> V_15 , V_11 ) ;
if ( ! line . V_12 )
F_3 ( line . V_16 , line . V_17 ) ;
if ( V_6 )
F_3 ( line . V_19 , line . V_18 ) ;
else
F_6 ( line . V_19 , line . V_18 ) ;
F_9 ( & V_8 -> V_15 , V_11 ) ;
return 0 ;
}
static void F_12 ( struct V_2 * V_3 , unsigned V_7 , int V_6 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
const struct V_9 line = V_8 -> V_10 [ V_7 ] ;
unsigned long V_11 ;
F_8 ( & V_8 -> V_15 , V_11 ) ;
if ( V_6 )
F_3 ( line . V_19 , line . V_18 ) ;
else
F_6 ( line . V_19 , line . V_18 ) ;
F_9 ( & V_8 -> V_15 , V_11 ) ;
}
static int F_13 ( struct V_2 * V_3 , unsigned V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
const struct V_9 * V_20 = V_8 -> V_10 ;
const struct V_9 line = V_20 [ V_7 ] ;
if ( line . V_21 )
return line . V_21 ;
if ( V_8 -> V_22 )
return V_8 -> V_23 ;
return - V_13 ;
}
static int F_14 ( struct V_1 * V_8 )
{
int V_24 = 0 ;
unsigned long V_11 ;
F_8 ( & V_8 -> V_15 , V_11 ) ;
if ( V_8 -> V_23 == 7 )
F_3 ( F_15 ( 7 ) , 0x7a ) ;
else if ( V_8 -> V_23 == 6 )
F_3 ( F_15 ( 7 ) , 0x7d ) ;
else if ( V_8 -> V_23 == 1 )
F_3 ( F_15 ( 6 ) , 0x7d ) ;
else
V_24 = - V_25 ;
F_9 ( & V_8 -> V_15 , V_11 ) ;
return V_24 ;
}
static void F_16 ( struct V_1 * V_8 )
{
unsigned long V_11 ;
F_8 ( & V_8 -> V_15 , V_11 ) ;
if ( V_8 -> V_23 == 7 )
F_6 ( F_15 ( 7 ) , 0x7a ) ;
else if ( V_8 -> V_23 == 6 )
F_6 ( F_15 ( 7 ) , 0x7d ) ;
else if ( V_8 -> V_23 == 1 )
F_6 ( F_15 ( 6 ) , 0x7d ) ;
else
F_17 ( V_8 -> V_2 . V_26 , L_1 , V_8 -> V_23 ) ;
F_9 ( & V_8 -> V_15 , V_11 ) ;
}
static int F_18 ( struct V_27 * V_28 )
{
enum V_29 V_20 = F_19 ( V_28 ) -> V_30 ;
struct V_31 * V_32 = V_28 -> V_26 . V_33 ;
struct V_34 * V_26 = & V_28 -> V_26 ;
const char * V_35 = F_20 ( V_26 ) ;
struct V_1 * V_8 ;
struct V_36 * V_37 ;
unsigned long V_11 ;
int V_24 ;
V_37 = F_21 ( V_28 , V_38 , 0 ) ;
if ( ! V_37 ) {
F_17 ( V_26 , L_2 ) ;
return - V_25 ;
}
V_8 = F_22 ( V_26 , sizeof( struct V_1 ) , V_39 ) ;
if ( ! V_8 )
return - V_40 ;
F_23 ( V_28 , V_8 ) ;
V_8 -> V_23 = V_37 -> V_41 ;
F_24 ( & V_8 -> V_15 ) ;
V_8 -> V_2 . V_42 = V_43 ;
V_8 -> V_2 . V_44 = V_35 ;
V_8 -> V_2 . V_26 = V_26 ;
V_8 -> V_2 . V_45 = F_7 ;
V_8 -> V_2 . V_46 = F_11 ;
V_8 -> V_2 . V_47 = F_10 ;
V_8 -> V_2 . V_48 = F_12 ;
V_8 -> V_2 . V_49 = F_13 ;
V_8 -> V_2 . V_50 = - 1 ;
if ( V_32 ) {
V_8 -> V_2 . V_50 = V_32 -> V_50 ;
V_8 -> V_22 = V_32 -> V_22 ;
}
switch ( V_20 ) {
case V_51 :
V_8 -> V_10 = V_52 ;
V_8 -> V_2 . V_53 = F_25 ( V_52 ) ;
if ( ! F_26 ( V_26 , 0x7a , 3 , V_35 ) ) {
F_17 ( V_26 , L_3 , V_35 ) ;
return - V_54 ;
}
break;
case V_55 :
V_8 -> V_10 = V_56 ;
V_8 -> V_2 . V_53 = F_25 ( V_56 ) ;
if ( ! F_26 ( V_26 , 0x7e , 2 , V_35 ) ) {
F_17 ( V_26 , L_3 , V_35 ) ;
return - V_54 ;
}
if ( V_57 )
break;
if ( ! F_26 ( V_26 , 0x7d , 1 , V_35 ) ) {
F_17 ( V_26 , L_4 , V_35 ) ;
return - V_54 ;
}
V_57 = true ;
break;
case V_58 :
case V_59 :
V_8 -> V_10 = V_60 ;
V_8 -> V_2 . V_53 = F_25 ( V_60 ) ;
if ( ! F_26 ( V_26 , 0x72 , 2 , V_35 ) ) {
F_17 ( V_26 , L_3 , V_35 ) ;
return - V_54 ;
}
if ( ! V_57 ) {
if ( ! F_26 ( V_26 , 0x7d , 1 , V_35 ) ) {
F_17 ( V_26 , L_4 , V_35 ) ;
return - V_54 ;
}
V_57 = true ;
}
F_8 ( & V_8 -> V_15 , V_11 ) ;
F_6 ( F_15 ( 4 ) , 0x7d ) ;
F_9 ( & V_8 -> V_15 , V_11 ) ;
break;
}
V_24 = F_27 ( & V_8 -> V_2 ) ;
if ( V_24 ) {
F_17 ( V_26 , L_5 ) ;
return V_24 ;
}
V_24 = F_14 ( V_8 ) ;
if ( V_24 ) {
F_17 ( V_26 , L_6 , V_8 -> V_23 ) ;
goto V_61;
}
return 0 ;
V_61:
if ( F_28 ( & V_8 -> V_2 ) )
F_17 ( V_26 , L_7 ) ;
return V_24 ;
}
static int F_29 ( struct V_27 * V_28 )
{
struct V_1 * V_8 = F_30 ( V_28 ) ;
F_16 ( V_8 ) ;
return F_28 ( & V_8 -> V_2 ) ;
}
