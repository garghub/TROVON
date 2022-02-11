static int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( V_4 , F_4 ( V_5 ) ) ;
while ( F_5 ( F_6 ( V_5 ) ) )
F_7 () ;
F_3 ( V_6 | V_7 | V_8 , F_8 ( V_5 ) ) ;
F_3 ( V_9 , F_9 ( V_5 ) ) ;
F_3 ( V_10 , F_10 ( V_5 ) ) ;
F_3 ( 0xFFFF , F_11 ( V_5 ) ) ;
F_3 ( V_2 -> V_11 * V_12 , F_12 ( V_5 ) ) ;
F_3 ( V_13 | V_14 , F_4 ( V_5 ) ) ;
F_13 ( & V_3 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( 0 , F_4 ( V_5 ) ) ;
F_13 ( & V_3 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned int V_15 )
{
V_2 -> V_11 = V_15 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned long V_16 , void * V_17 )
{
const char * V_18 = V_17 ;
if ( V_18 ) {
if ( V_18 [ 0 ] == 'h' )
V_16 = V_19 ;
else if ( V_18 [ 0 ] == 's' )
V_16 = V_20 ;
}
if ( V_16 == V_20 ) {
F_3 ( V_21 , F_9 ( V_5 ) ) ;
F_3 ( V_22 , F_8 ( V_5 ) ) ;
} else {
F_3 ( 13000 , F_11 ( V_5 ) ) ;
F_3 ( V_6 | V_23 | V_24 , F_8 ( V_5 ) ) ;
}
F_17 ( 1000 ) ;
return V_25 ;
}
static int F_18 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
int V_30 = 0 ;
F_19 ( & V_31 , V_32 , & V_27 -> V_33 ) ;
V_29 = F_20 ( V_27 , V_34 , 0 ) ;
V_5 = F_21 ( & V_27 -> V_33 , V_29 ) ;
if ( F_22 ( V_5 ) )
return F_23 ( V_5 ) ;
V_35 = F_24 ( & V_27 -> V_33 , NULL ) ;
if ( F_22 ( V_35 ) )
return F_23 ( V_35 ) ;
V_30 = F_25 ( V_35 ) ;
if ( V_30 )
return V_30 ;
V_31 . V_36 = ( F_5 ( F_26 ( V_5 ) ) & V_37 ) ?
V_38 : 0 ;
V_31 . V_39 = & V_27 -> V_33 ;
F_27 ( & V_31 , V_40 ) ;
F_28 ( & V_31 , 128 ) ;
F_14 ( & V_31 ) ;
V_30 = F_29 ( & V_31 ) ;
if ( V_30 < 0 ) {
F_30 ( & V_27 -> V_33 , L_1 ) ;
goto V_41;
}
F_31 ( & V_27 -> V_33 , L_2 , V_31 . V_11 ) ;
return 0 ;
V_41:
F_32 ( V_35 ) ;
return V_30 ;
}
static int F_33 ( struct V_26 * V_27 )
{
F_34 ( & V_31 ) ;
F_32 ( V_35 ) ;
return 0 ;
}
