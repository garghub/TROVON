static int F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned char * V_4 , int V_5 , T_1 V_6 )
{
int V_7 ;
unsigned char * V_8 ;
if ( ! V_2 )
return - V_9 ;
V_8 = F_2 ( V_4 , V_5 , V_10 ) ;
if ( ! V_8 ) {
F_3 ( & V_2 -> V_2 , L_1 ,
V_11 , V_5 ) ;
return - V_12 ;
}
V_7 = F_4 ( V_2 , F_5 ( V_2 , 0 ) , V_6 ,
V_13 | V_14 | V_15 ,
V_3 , 0 , V_8 , V_5 , 3000 ) ;
F_6 ( V_8 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned short V_16 ,
unsigned char V_17 )
{
int V_18 = F_1 ( V_2 , V_16 , & V_17 , 1 , V_19 ) ;
if ( V_18 < 0 )
F_3 ( & V_2 -> V_2 , L_2 ,
V_11 , V_17 , V_18 ) ;
return V_18 ;
}
int F_8 ( struct V_1 * V_2 , unsigned char V_17 )
{
return F_7 ( V_2 , V_20 . V_16 , V_17 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_21 V_22 ,
const char * V_23 )
{
int V_24 = - V_25 ;
const struct V_26 * V_26 = NULL ;
const struct V_27 * V_28 ;
if ( F_10 ( & V_26 , V_23 ,
& V_2 -> V_2 ) ) {
F_3 ( & V_2 -> V_2 ,
L_3 ,
V_11 , V_23 ) ;
goto V_29;
}
V_24 = F_7 ( V_2 , V_22 . V_16 , 0 ) ;
if ( V_24 < 0 )
goto V_29;
V_28 = ( const struct V_27 * ) V_26 -> V_4 ;
for (; V_28 ; V_28 = F_11 ( V_28 ) ) {
if ( F_12 ( V_28 -> V_30 ) > V_22 . V_31 ) {
V_24 = F_1 ( V_2 , F_12 ( V_28 -> V_30 ) ,
( unsigned char * ) V_28 -> V_4 ,
F_13 ( V_28 -> V_32 ) , V_33 ) ;
if ( V_24 < 0 ) {
F_3 ( & V_2 -> V_2 , L_4
L_5
L_6 , V_11 , V_24 ,
F_12 ( V_28 -> V_30 ) , V_28 -> V_4 ,
F_13 ( V_28 -> V_32 ) ) ;
goto V_29;
}
}
}
V_24 = F_7 ( V_2 , V_22 . V_16 , 1 ) ;
if ( V_24 < 0 )
goto V_29;
V_28 = ( const struct V_27 * ) V_26 -> V_4 ;
for (; V_28 ; V_28 = F_11 ( V_28 ) ) {
if ( F_12 ( V_28 -> V_30 ) <= V_22 . V_31 ) {
V_24 = F_1 ( V_2 , F_12 ( V_28 -> V_30 ) ,
( unsigned char * ) V_28 -> V_4 ,
F_13 ( V_28 -> V_32 ) , V_19 ) ;
if ( V_24 < 0 ) {
F_3 ( & V_2 -> V_2 , L_4
L_7
L_6 , V_11 , V_24 ,
F_12 ( V_28 -> V_30 ) , V_28 -> V_4 ,
F_13 ( V_28 -> V_32 ) ) ;
goto V_29;
}
}
}
V_24 = F_7 ( V_2 , V_22 . V_16 , 0 ) ;
V_29:
F_14 ( V_26 ) ;
return V_24 ;
}
int F_15 ( struct V_1 * V_2 ,
const char * V_23 )
{
return F_9 ( V_2 , V_20 , V_23 ) ;
}
