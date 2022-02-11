static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_6 = V_5 -> V_6 ;
unsigned long V_7 ;
V_7 = F_3 ( V_6 + V_8 ) ;
V_7 &= ~ ( 0xf << F_4 ( V_3 ) ) ;
F_5 ( V_7 , V_6 + V_8 ) ;
F_6 ( L_1 , V_9 , V_6 , V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_6 = V_5 -> V_6 ;
unsigned long V_7 ;
unsigned long V_11 ;
V_7 = F_3 ( V_6 + V_8 ) ;
V_7 &= ~ ( 0xf << F_4 ( V_3 ) ) ;
V_7 |= 0x1 << F_4 ( V_3 ) ;
V_11 = F_3 ( V_6 + V_12 ) ;
if ( V_10 )
V_11 |= 1 << V_3 ;
else
V_11 &= ~ ( 1 << V_3 ) ;
F_5 ( V_11 , V_6 + V_12 ) ;
F_5 ( V_7 , V_6 + V_8 ) ;
F_5 ( V_11 , V_6 + V_12 ) ;
F_6 ( L_2 , V_9 , V_6 , V_7 , V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_6 = V_5 -> V_6 ;
void T_1 * V_13 = V_6 ;
unsigned long V_7 ;
if ( V_3 > 7 )
V_3 -= 8 ;
else
V_13 -= 4 ;
V_7 = F_3 ( V_13 ) ;
V_7 &= ~ ( 0xf << F_4 ( V_3 ) ) ;
F_5 ( V_7 , V_13 ) ;
F_6 ( L_3 , V_9 , V_6 , V_7 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
void T_1 * V_6 = V_5 -> V_6 ;
void T_1 * V_13 = V_6 ;
unsigned long V_7 ;
unsigned long V_11 ;
unsigned V_14 = V_3 ;
if ( V_14 > 7 )
V_14 -= 8 ;
else
V_13 -= 4 ;
V_7 = F_3 ( V_13 ) ;
V_7 &= ~ ( 0xf << F_4 ( V_14 ) ) ;
V_7 |= 0x1 << F_4 ( V_14 ) ;
V_11 = F_3 ( V_6 + V_12 ) ;
if ( V_10 )
V_11 |= 1 << V_3 ;
else
V_11 &= ~ ( 1 << V_3 ) ;
F_5 ( V_11 , V_6 + V_12 ) ;
F_5 ( V_7 , V_13 ) ;
F_5 ( V_11 , V_6 + V_12 ) ;
F_6 ( L_2 , V_9 , V_6 , V_7 , V_11 ) ;
return 0 ;
}
void T_2 F_10 ( struct V_4 * V_2 )
{
V_2 -> V_2 . V_15 = F_1 ;
V_2 -> V_2 . V_16 = F_7 ;
V_2 -> V_17 = F_11 ( & V_18 ) ;
}
void T_2 F_12 ( struct V_4 * V_2 )
{
V_2 -> V_2 . V_15 = F_8 ;
V_2 -> V_2 . V_16 = F_9 ;
V_2 -> V_17 = F_11 ( & V_18 ) ;
}
void T_2 F_13 ( struct V_4 * V_2 ,
int V_19 )
{
for (; V_19 > 0 ; V_19 -- , V_2 ++ ) {
F_10 ( V_2 ) ;
F_14 ( V_2 ) ;
}
}
void T_2 F_15 ( struct V_4 * V_2 ,
int V_19 )
{
for (; V_19 > 0 ; V_19 -- , V_2 ++ ) {
F_12 ( V_2 ) ;
F_14 ( V_2 ) ;
}
}
void T_2 F_16 ( struct V_4 * V_2 ,
int V_19 )
{
for (; V_19 > 0 ; V_19 -- , V_2 ++ )
F_14 ( V_2 ) ;
}
