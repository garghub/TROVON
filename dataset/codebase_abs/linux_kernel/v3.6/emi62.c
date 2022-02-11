static int F_1 ( struct V_1 * V_2 , int V_3 ,
const unsigned char * V_4 , int V_5 ,
T_1 V_6 )
{
int V_7 ;
unsigned char * V_8 = F_2 ( V_4 , V_5 , V_9 ) ;
if ( ! V_8 ) {
F_3 ( & V_2 -> V_2 , L_1 , V_5 ) ;
return - V_10 ;
}
V_7 = F_4 ( V_2 , F_5 ( V_2 , 0 ) , V_6 , 0x40 , V_3 , 0 , V_8 , V_5 , 300 ) ;
F_6 ( V_8 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned char V_11 )
{
int V_12 ;
F_8 ( & V_2 -> V_2 , L_2 , V_13 , V_11 ) ;
V_12 = F_1 ( V_2 , V_14 , & V_11 , 1 , 0xa0 ) ;
if ( V_12 < 0 )
F_3 ( & V_2 -> V_2 , L_3 , V_11 ) ;
return V_12 ;
}
static int F_9 ( struct V_1 * V_2 )
{
const struct V_15 * V_16 = NULL ;
const struct V_15 * V_17 = NULL ;
const struct V_15 * V_18 = NULL ;
const struct V_19 * V_20 ;
int V_21 = - V_10 ;
int V_22 ;
T_2 V_23 ;
T_1 * V_24 ;
F_10 ( & V_2 -> V_2 , L_4 ) ;
V_24 = F_11 ( V_25 , V_9 ) ;
if ( ! V_24 )
goto V_26;
V_21 = F_12 ( & V_16 , L_5 , & V_2 -> V_2 ) ;
if ( V_21 )
goto V_27;
V_21 = F_12 ( & V_17 , L_6 ,
& V_2 -> V_2 ) ;
if ( V_21 )
goto V_27;
V_21 = F_12 ( & V_18 , V_28 , & V_2 -> V_2 ) ;
if ( V_21 ) {
V_27:
goto V_26;
}
V_21 = F_7 ( V_2 , 1 ) ;
if ( V_21 < 0 )
goto V_26;
V_20 = ( const struct V_19 * ) V_16 -> V_4 ;
while ( V_20 ) {
V_21 = F_1 ( V_2 , F_13 ( V_20 -> V_23 ) ,
V_20 -> V_4 , F_14 ( V_20 -> V_29 ) ,
V_30 ) ;
if ( V_21 < 0 )
goto V_26;
V_20 = F_15 ( V_20 ) ;
}
V_21 = F_7 ( V_2 , 0 ) ;
if ( V_21 < 0 )
goto V_26;
F_16 ( 250 ) ;
V_20 = ( const struct V_19 * ) V_17 -> V_4 ;
do {
V_22 = 0 ;
V_23 = F_13 ( V_20 -> V_23 ) ;
while ( V_20 && ( V_22 + F_14 ( V_20 -> V_29 ) < V_25 ) ) {
memcpy ( V_24 + V_22 , V_20 -> V_4 , F_14 ( V_20 -> V_29 ) ) ;
V_22 += F_14 ( V_20 -> V_29 ) ;
V_20 = F_15 ( V_20 ) ;
}
V_21 = F_1 ( V_2 , V_23 , V_24 , V_22 , V_31 ) ;
if ( V_21 < 0 )
goto V_26;
} while ( V_20 );
V_21 = F_7 ( V_2 , 1 ) ;
if ( V_21 < 0 )
goto V_26;
for ( V_20 = ( const struct V_19 * ) V_16 -> V_4 ;
V_20 ; V_20 = F_15 ( V_20 ) ) {
V_21 = F_1 ( V_2 , F_13 ( V_20 -> V_23 ) ,
V_20 -> V_4 , F_14 ( V_20 -> V_29 ) ,
V_30 ) ;
if ( V_21 < 0 )
goto V_26;
}
V_21 = F_7 ( V_2 , 0 ) ;
if ( V_21 < 0 )
goto V_26;
F_16 ( 250 ) ;
for ( V_20 = ( const struct V_19 * ) V_18 -> V_4 ;
V_20 ; V_20 = F_15 ( V_20 ) ) {
if ( ! F_17 ( F_13 ( V_20 -> V_23 ) ) ) {
V_21 = F_1 ( V_2 , F_13 ( V_20 -> V_23 ) ,
V_20 -> V_4 , F_14 ( V_20 -> V_29 ) ,
V_32 ) ;
if ( V_21 < 0 )
goto V_26;
}
}
V_21 = F_7 ( V_2 , 1 ) ;
if ( V_21 < 0 )
goto V_26;
for ( V_20 = ( const struct V_19 * ) V_18 -> V_4 ;
V_20 ; V_20 = F_15 ( V_20 ) ) {
if ( F_17 ( F_13 ( V_20 -> V_23 ) ) ) {
V_21 = F_1 ( V_2 , F_13 ( V_20 -> V_23 ) ,
V_20 -> V_4 , F_14 ( V_20 -> V_29 ) ,
V_32 ) ;
if ( V_21 < 0 )
goto V_26;
}
}
V_21 = F_7 ( V_2 , 0 ) ;
if ( V_21 < 0 )
goto V_26;
F_16 ( 250 ) ;
F_18 ( V_16 ) ;
F_18 ( V_17 ) ;
F_18 ( V_18 ) ;
F_6 ( V_24 ) ;
return 1 ;
V_26:
if ( V_21 < 0 )
F_3 ( & V_2 -> V_2 , L_7 ,
V_13 , V_21 ) ;
F_18 ( V_16 ) ;
F_18 ( V_17 ) ;
F_18 ( V_18 ) ;
F_6 ( V_24 ) ;
F_3 ( & V_2 -> V_2 , L_8 ) ;
return V_21 ;
}
static int F_19 ( struct V_33 * V_34 , const struct V_35 * V_36 )
{
struct V_1 * V_2 = F_20 ( V_34 ) ;
F_10 ( & V_34 -> V_2 , L_9 ) ;
F_8 ( & V_34 -> V_2 , L_10 , V_13 ) ;
F_9 ( V_2 ) ;
return - V_37 ;
}
static void F_21 ( struct V_33 * V_34 )
{
}
