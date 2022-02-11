static inline unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_2 ( V_2 -> V_4 + ( V_3 << 2 ) ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
unsigned long V_5 , unsigned long V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + ( V_3 << 2 ) ) ;
}
struct V_6 * F_5 ( struct V_7 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_6 * V_11 ;
struct V_12 args ;
int V_13 ;
V_13 = F_6 ( V_9 , L_1 ,
L_2 , 0 ,
& args ) ;
if ( V_13 < 0 )
return F_7 ( V_13 ) ;
V_11 = F_8 ( sizeof( * V_11 ) , V_14 ) ;
if ( ! V_11 ) {
F_9 ( args . V_9 ) ;
V_13 = - V_15 ;
goto V_16;
}
V_11 -> V_17 = F_10 ( args . V_9 ) ;
if ( ! V_11 -> V_17 ) {
F_9 ( args . V_9 ) ;
V_13 = - V_18 ;
goto free;
}
F_9 ( args . V_9 ) ;
V_11 -> V_2 = F_11 ( V_11 -> V_17 ) ;
if ( ! V_11 -> V_2 ) {
V_13 = - V_19 ;
goto V_20;
}
V_11 -> V_21 = args . args [ 0 ] ;
V_11 -> V_7 = V_7 ;
return V_11 ;
V_20:
F_12 ( V_11 -> V_17 ) ;
free:
F_13 ( V_11 ) ;
V_16:
return F_7 ( V_13 ) ;
}
void F_14 ( struct V_6 * V_7 )
{
F_12 ( V_7 -> V_17 ) ;
F_13 ( V_7 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
unsigned long V_22 = V_23 + F_16 ( 250 ) ;
unsigned long V_5 ;
while ( F_17 ( V_23 , V_22 ) ) {
V_5 = F_1 ( V_2 , V_24 ) ;
if ( ( V_5 & V_25 ) == 0 &&
( V_5 & V_26 ) != 0 )
return 0 ;
F_18 ( 10 , 50 ) ;
}
return - V_27 ;
}
int F_19 ( struct V_6 * V_7 )
{
unsigned long V_5 ;
unsigned int V_28 ;
int V_13 ;
V_13 = F_20 ( V_7 -> V_2 -> V_29 ) ;
if ( V_13 < 0 )
return V_13 ;
F_21 ( & V_7 -> V_2 -> V_30 ) ;
V_5 = F_1 ( V_7 -> V_2 , V_31 ) ;
V_5 &= ~ V_32 ;
V_5 |= V_33 ;
F_3 ( V_7 -> V_2 , V_5 , V_31 ) ;
V_5 = F_1 ( V_7 -> V_2 , V_34 ) ;
V_5 &= ~ V_35 ;
F_3 ( V_7 -> V_2 , V_5 , V_34 ) ;
for ( V_28 = 0 ; V_28 < F_22 ( V_36 ) ; V_28 ++ ) {
if ( V_7 -> V_21 & F_23 ( V_28 ) )
V_5 = V_37 |
F_24 ( 0 ) |
F_25 ( 4 ) |
F_26 ( 5 ) ;
else
V_5 = 0 ;
F_3 ( V_7 -> V_2 , V_5 , V_36 [ V_28 ] . V_3 ) ;
}
F_3 ( V_7 -> V_2 , V_38 , V_39 ) ;
V_13 = F_15 ( V_7 -> V_2 ) ;
F_27 ( & V_7 -> V_2 -> V_30 ) ;
F_28 ( V_7 -> V_2 -> V_29 ) ;
return V_13 ;
}
static int F_29 ( struct V_40 * V_17 )
{
struct V_1 * V_2 ;
struct V_41 * V_42 ;
int V_13 ;
V_2 = F_30 ( & V_17 -> V_11 , sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 )
return - V_15 ;
V_42 = F_31 ( V_17 , V_43 , 0 ) ;
V_2 -> V_4 = F_32 ( & V_17 -> V_11 , V_42 ) ;
if ( F_33 ( V_2 -> V_4 ) )
return F_34 ( V_2 -> V_4 ) ;
F_35 ( & V_2 -> V_30 ) ;
V_2 -> V_29 = F_36 ( & V_17 -> V_11 , NULL ) ;
if ( F_33 ( V_2 -> V_29 ) ) {
F_37 ( & V_17 -> V_11 , L_3 ) ;
return F_34 ( V_2 -> V_29 ) ;
}
V_13 = F_38 ( V_2 -> V_29 ) ;
if ( V_13 < 0 )
return V_13 ;
F_39 ( V_17 , V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_40 * V_17 )
{
struct V_1 * V_2 = F_11 ( V_17 ) ;
F_41 ( V_2 -> V_29 ) ;
return 0 ;
}
