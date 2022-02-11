void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
unsigned long V_7 ;
unsigned int V_8 ;
struct V_9 * V_10 ;
V_6 = V_2 -> V_6 ;
V_4 = F_2 ( V_6 -> V_11 . V_12 ) ;
if ( V_2 -> V_13 )
F_3 ( V_2 -> V_13 ) ;
F_4 ( F_5 ( V_4 ) , & V_2 -> V_14 ) ;
F_6 ( V_4 -> V_15 , V_2 ) ;
do {
V_8 = F_7 ( & V_4 -> V_16 ) ;
if ( ! F_8 ( & V_4 -> V_17 ) ) {
struct V_18 * V_19 ;
F_9 ( & V_4 -> V_16 , V_7 ) ;
V_19 = F_10 ( & V_4 -> V_17 , struct V_18 ,
V_20 ) ;
V_6 = F_11 ( V_19 ) ;
V_10 = V_6 -> V_10 ;
F_12 ( & V_10 -> V_21 . V_20 ) ;
F_13 ( & V_4 -> V_16 , V_7 ) ;
F_14 ( V_6 , V_22 ) ;
break;
}
} while ( F_15 ( & V_4 -> V_16 , V_8 ) );
}
struct V_1 * F_16 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = F_17 ( - V_23 ) ;
unsigned long V_7 ;
F_18 ( & V_6 -> V_24 , V_7 ) ;
F_19 ( & V_4 -> V_16 ) ;
if ( V_25 [ V_6 -> V_26 ] & V_27 ) {
struct V_9 * V_10 ;
V_2 = F_20 ( V_4 -> V_15 , V_28 ) ;
if ( V_2 )
goto V_29;
V_10 = V_6 -> V_10 ;
if ( F_8 ( & V_10 -> V_21 . V_20 ) ) {
V_4 -> V_30 ++ ;
V_6 -> V_31 |= V_22 ;
F_21 ( & V_10 -> V_21 . V_20 , & V_4 -> V_17 ) ;
F_22 ( V_6 , V_22 ) ;
F_23 ( & V_6 -> V_32 ) ;
}
V_6 -> V_31 &= ~ V_33 ;
}
V_29:
F_24 ( & V_4 -> V_16 ) ;
F_25 ( & V_6 -> V_24 , V_7 ) ;
return V_2 ;
}
static void F_26 ( void * V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
}
int F_27 ( struct V_3 * V_4 )
{
char V_35 [ V_36 ] ;
struct V_37 * V_38 = F_5 ( V_4 ) ;
snprintf ( V_35 , sizeof( V_35 ) , L_1 , V_38 -> V_39 ) ;
V_4 -> V_15 = F_28 ( V_35 ,
sizeof( struct V_1 ) ,
0 , V_40 ,
F_26 ) ;
if ( ! V_4 -> V_15 )
return - V_41 ;
return 0 ;
}
void F_29 ( struct V_3 * V_4 )
{
F_30 ( V_4 -> V_15 ) ;
V_4 -> V_15 = NULL ;
}
