static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
unsigned char V_4 ;
unsigned int V_5 ;
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_3 ) ;
V_5 = V_2 -> V_9 ;
V_4 = ( V_7 -> V_10 . V_11 |= 4 ) ;
F_4 ( V_7 , V_12 , 256 - V_5 ) ;
F_4 ( V_7 , V_13 , V_4 ) ;
F_5 ( V_7 , 0x04 , V_4 >> 2 ) ;
F_6 ( & V_7 -> V_8 , V_3 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
unsigned char V_4 ;
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_3 ) ;
V_4 = ( V_7 -> V_10 . V_11 &= ~ 4 ) ;
F_4 ( V_7 , V_13 , V_4 ) ;
F_6 ( & V_7 -> V_8 , V_3 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
unsigned char V_4 ;
unsigned int V_5 ;
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_3 ) ;
V_5 = V_2 -> V_9 ;
V_4 = ( V_7 -> V_10 . V_11 |= 8 ) ;
F_4 ( V_7 , V_14 , 256 - V_5 ) ;
F_4 ( V_7 , V_13 , V_4 ) ;
F_5 ( V_7 , 0x04 , V_4 >> 2 ) ;
F_6 ( & V_7 -> V_8 , V_3 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
unsigned char V_4 ;
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_3 ) ;
V_4 = ( V_7 -> V_10 . V_11 &= ~ 8 ) ;
F_4 ( V_7 , V_13 , V_4 ) ;
F_6 ( & V_7 -> V_8 , V_3 ) ;
return 0 ;
}
static void F_10 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_10 . V_15 ;
if ( V_2 == NULL )
return;
F_11 ( V_2 , V_2 -> V_9 ) ;
}
static void F_12 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_10 . V_16 ;
if ( V_2 == NULL )
return;
F_11 ( V_2 , V_2 -> V_9 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_17 ;
V_7 -> V_10 . V_15 = NULL ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_17 ;
V_7 -> V_10 . V_16 = NULL ;
}
void F_15 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
struct V_18 V_19 ;
if ( V_7 -> V_10 . V_15 != NULL || V_7 -> V_10 . V_16 != NULL )
return;
V_7 -> V_10 . V_20 = F_10 ;
V_7 -> V_10 . V_21 = F_12 ;
V_19 . V_22 = V_23 ;
V_19 . V_24 = V_25 ;
V_19 . V_26 = V_7 -> V_26 -> V_27 ;
V_19 . V_28 = V_7 -> V_29 ;
V_19 . V_30 = 0 ;
if ( F_16 ( V_7 -> V_26 , L_1 , & V_19 , & V_2 ) >= 0 ) {
strcpy ( V_2 -> V_31 , L_2 ) ;
V_2 -> V_17 = V_7 ;
V_2 -> V_32 = F_13 ;
V_2 -> V_33 = V_34 ;
}
V_7 -> V_10 . V_15 = V_2 ;
V_19 . V_28 ++ ;
if ( F_16 ( V_7 -> V_26 , L_1 , & V_19 , & V_2 ) >= 0 ) {
strcpy ( V_2 -> V_31 , L_3 ) ;
V_2 -> V_17 = V_7 ;
V_2 -> V_32 = F_14 ;
V_2 -> V_33 = V_35 ;
}
V_7 -> V_10 . V_16 = V_2 ;
}
void F_17 ( struct V_6 * V_7 )
{
F_18 ( V_7 , V_36 | V_37 ) ;
if ( V_7 -> V_10 . V_15 ) {
F_19 ( V_7 -> V_26 , V_7 -> V_10 . V_15 ) ;
V_7 -> V_10 . V_15 = NULL ;
}
if ( V_7 -> V_10 . V_16 ) {
F_19 ( V_7 -> V_26 , V_7 -> V_10 . V_16 ) ;
V_7 -> V_10 . V_16 = NULL ;
}
}
