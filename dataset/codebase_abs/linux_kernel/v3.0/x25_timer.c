void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( & V_4 -> V_5 , V_6 , ( unsigned long ) V_2 ) ;
V_2 -> V_7 . V_8 = ( unsigned long ) V_2 ;
V_2 -> V_7 . V_9 = & V_10 ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_7 , V_11 + 5 * V_12 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_7 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( & V_4 -> V_5 , V_11 + V_4 -> V_13 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( & V_4 -> V_5 , V_11 + V_4 -> V_14 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( & V_4 -> V_5 , V_11 + V_4 -> V_15 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( & V_4 -> V_5 , V_11 + V_4 -> V_16 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_7 ( & F_2 ( V_2 ) -> V_5 ) ;
}
unsigned long F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_14 ( & V_4 -> V_5 ) )
return 0 ;
return V_4 -> V_5 . V_17 - V_11 ;
}
static void V_10 ( unsigned long V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 ;
F_15 ( V_2 ) ;
if ( F_16 ( V_2 ) )
goto V_19;
switch ( F_2 ( V_2 ) -> V_20 ) {
case V_21 :
if ( F_17 ( V_2 , V_22 ) ||
( V_2 -> V_23 == V_24 &&
F_17 ( V_2 , V_25 ) ) ) {
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
return;
}
break;
case V_26 :
F_20 ( V_2 ) ;
break;
}
V_19:
F_4 ( V_2 ) ;
F_18 ( V_2 ) ;
}
static inline void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_4 -> V_20 ) {
case V_26 :
if ( V_4 -> V_27 & V_28 ) {
V_4 -> V_27 &= ~ V_28 ;
F_22 ( V_2 ) ;
}
break;
case V_29 :
case V_30 :
F_23 ( V_2 , V_31 ) ;
V_4 -> V_20 = V_32 ;
F_11 ( V_2 ) ;
break;
case V_32 :
F_24 ( V_2 , V_33 , 0 , 0 ) ;
break;
}
}
static void V_6 ( unsigned long V_18 )
{
struct V_1 * V_2 = (struct V_1 * ) V_18 ;
F_15 ( V_2 ) ;
if ( F_16 ( V_2 ) ) {
if ( F_2 ( V_2 ) -> V_20 == V_26 )
F_8 ( V_2 ) ;
} else
F_21 ( V_2 ) ;
F_18 ( V_2 ) ;
}
