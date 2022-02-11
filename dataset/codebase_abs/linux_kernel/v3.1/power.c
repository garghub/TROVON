void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 = V_4 -> V_7 & 0xffff ;
V_4 -> V_8 &= 0xffff ;
V_4 -> V_9 = true ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = false ;
F_2 ( & V_12 ) ;
F_3 ( & V_13 ) ;
V_4 -> V_14 -> V_15 ( V_2 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_16 -> V_2 ) ;
F_6 ( & V_2 -> V_16 -> V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_11 )
return;
V_4 -> V_14 -> V_17 ( V_2 ) ;
V_4 -> V_14 -> V_18 ( V_2 ) ;
V_4 -> V_9 = false ;
}
static void F_8 ( struct V_19 * V_16 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_11 == false )
return;
V_4 -> V_14 -> V_20 ( V_2 ) ;
V_4 -> V_11 = false ;
V_4 -> V_9 = true ;
F_10 ( V_4 -> V_21 | V_22 , V_23 ) ;
F_11 ( V_16 , V_24 ,
V_4 -> V_25 | V_26 ) ;
V_4 -> V_14 -> V_27 ( V_2 ) ;
}
static void F_12 ( struct V_19 * V_16 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_28 , V_29 ;
if ( V_4 -> V_11 )
return;
F_13 ( V_16 ) ;
F_14 ( V_16 , 0x5C , & V_28 ) ;
V_4 -> V_30 = V_28 ;
F_14 ( V_16 , 0xFC , & V_29 ) ;
V_4 -> V_31 = V_29 ;
F_14 ( V_16 , V_32 , & V_4 -> V_33 ) ;
F_14 ( V_16 , V_34 , & V_4 -> V_35 ) ;
F_15 ( V_16 ) ;
F_16 ( V_16 , V_36 ) ;
V_4 -> V_11 = true ;
}
static bool F_17 ( struct V_19 * V_16 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_37 ;
if ( ! V_4 -> V_11 )
return true ;
F_16 ( V_16 , V_38 ) ;
F_18 ( V_16 ) ;
F_19 ( V_16 , 0x5c , V_4 -> V_30 ) ;
F_19 ( V_16 , 0xFC , V_4 -> V_31 ) ;
F_19 ( V_16 , V_32 , V_4 -> V_33 ) ;
F_19 ( V_16 , V_34 , V_4 -> V_35 ) ;
V_37 = F_20 ( V_16 ) ;
if ( V_37 != 0 )
F_21 ( & V_16 -> V_2 , L_1 , V_37 ) ;
else
V_4 -> V_11 = false ;
return ! V_4 -> V_11 ;
}
int F_22 ( struct V_39 * V_40 )
{
struct V_19 * V_16 = F_23 ( V_40 , struct V_19 , V_2 ) ;
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_24 ( & V_13 ) ;
if ( ! V_4 -> V_11 ) {
if ( V_4 -> V_10 ) {
F_25 ( & V_13 ) ;
return - V_41 ;
}
F_26 ( V_2 ) ;
F_7 ( V_2 ) ;
F_12 ( V_16 ) ;
}
F_25 ( & V_13 ) ;
return 0 ;
}
int F_27 ( struct V_39 * V_40 )
{
struct V_19 * V_16 = F_23 ( V_40 , struct V_19 , V_2 ) ;
struct V_1 * V_2 = F_9 ( V_16 ) ;
F_24 ( & V_13 ) ;
F_17 ( V_16 ) ;
F_8 ( V_16 ) ;
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
F_25 ( & V_13 ) ;
return 0 ;
}
bool F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return V_4 -> V_9 ;
}
bool F_31 ( struct V_1 * V_2 , bool V_42 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_37 ;
unsigned long V_43 ;
F_32 ( & V_12 , V_43 ) ;
if ( V_4 -> V_9 ) {
V_4 -> V_10 ++ ;
F_33 ( & V_2 -> V_16 -> V_2 ) ;
F_34 ( & V_12 , V_43 ) ;
return true ;
}
if ( V_42 == false )
goto V_44;
V_37 = F_17 ( V_2 -> V_16 ) ;
if ( V_37 == 0 ) {
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
F_33 ( & V_2 -> V_16 -> V_2 ) ;
V_4 -> V_10 ++ ;
F_34 ( & V_12 , V_43 ) ;
return true ;
}
V_44:
F_34 ( & V_12 , V_43 ) ;
return false ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned long V_43 ;
F_32 ( & V_12 , V_43 ) ;
V_4 -> V_10 -- ;
F_36 ( V_4 -> V_10 < 0 ) ;
F_34 ( & V_12 , V_43 ) ;
F_37 ( & V_2 -> V_16 -> V_2 ) ;
}
int F_38 ( struct V_39 * V_2 )
{
return F_22 ( V_2 ) ;
}
int F_39 ( struct V_39 * V_2 )
{
return 0 ;
}
int F_40 ( struct V_39 * V_2 )
{
struct V_1 * V_45 = F_9 ( F_41 ( V_2 ) ) ;
struct V_3 * V_4 = V_45 -> V_5 ;
if ( V_4 -> V_10 )
return 0 ;
else
return 1 ;
}
