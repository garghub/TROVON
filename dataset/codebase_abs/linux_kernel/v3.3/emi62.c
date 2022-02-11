static int F_1 ( struct V_1 * V_2 , int V_3 ,
const unsigned char * V_4 , int V_5 ,
T_1 V_6 )
{
int V_7 ;
unsigned char * V_8 = F_2 ( V_4 , V_5 , V_9 ) ;
if ( ! V_8 ) {
F_3 ( L_1 , V_5 ) ;
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
if ( V_12 < 0 ) {
F_3 ( L_3 , V_11 ) ;
}
return V_12 ;
}
static int F_9 ( struct V_1 * V_2 )
{
const struct V_15 * V_16 = NULL ;
const struct V_15 * V_17 = NULL ;
const struct V_15 * V_18 = NULL ;
const struct V_19 * V_20 ;
int F_3 ;
int V_21 ;
T_2 V_22 ;
T_1 * V_23 ;
F_10 ( & V_2 -> V_2 , L_4 ) ;
V_23 = F_11 ( V_24 , V_9 ) ;
if ( ! V_23 ) {
F_3 ( L_5 , V_13 , - V_10 ) ;
F_3 = - V_10 ;
goto V_25;
}
F_3 = F_12 ( & V_16 , L_6 , & V_2 -> V_2 ) ;
if ( F_3 )
goto V_26;
F_3 = F_12 ( & V_17 , L_7 ,
& V_2 -> V_2 ) ;
if ( F_3 )
goto V_26;
F_3 = F_12 ( & V_18 , V_27 , & V_2 -> V_2 ) ;
if ( F_3 ) {
V_26:
F_3 ( L_8 , V_13 ) ;
goto V_25;
}
F_3 = F_7 ( V_2 , 1 ) ;
if ( F_3 < 0 ) {
F_3 ( L_5 , V_13 , F_3 ) ;
goto V_25;
}
V_20 = ( const struct V_19 * ) V_16 -> V_4 ;
while ( V_20 ) {
F_3 = F_1 ( V_2 , F_13 ( V_20 -> V_22 ) ,
V_20 -> V_4 , F_14 ( V_20 -> V_28 ) ,
V_29 ) ;
if ( F_3 < 0 ) {
F_3 ( L_5 , V_13 , F_3 ) ;
goto V_25;
}
V_20 = F_15 ( V_20 ) ;
}
F_3 = F_7 ( V_2 , 0 ) ;
if ( F_3 < 0 ) {
F_3 ( L_5 , V_13 , F_3 ) ;
goto V_25;
}
F_16 ( 250 ) ;
V_20 = ( const struct V_19 * ) V_17 -> V_4 ;
do {
V_21 = 0 ;
V_22 = F_13 ( V_20 -> V_22 ) ;
while ( V_20 && ( V_21 + F_14 ( V_20 -> V_28 ) < V_24 ) ) {
memcpy ( V_23 + V_21 , V_20 -> V_4 , F_14 ( V_20 -> V_28 ) ) ;
V_21 += F_14 ( V_20 -> V_28 ) ;
V_20 = F_15 ( V_20 ) ;
}
F_3 = F_1 ( V_2 , V_22 , V_23 , V_21 , V_30 ) ;
if ( F_3 < 0 ) {
F_3 ( L_5 , V_13 , F_3 ) ;
goto V_25;
}
} while ( V_20 );
F_3 = F_7 ( V_2 , 1 ) ;
if ( F_3 < 0 ) {
F_3 ( L_5 , V_13 , F_3 ) ;
goto V_25;
}
for ( V_20 = ( const struct V_19 * ) V_16 -> V_4 ;
V_20 ; V_20 = F_15 ( V_20 ) ) {
F_3 = F_1 ( V_2 , F_13 ( V_20 -> V_22 ) ,
V_20 -> V_4 , F_14 ( V_20 -> V_28 ) ,
V_29 ) ;
if ( F_3 < 0 ) {
F_3 ( L_5 , V_13 , F_3 ) ;
goto V_25;
}
}
F_3 = F_7 ( V_2 , 0 ) ;
if ( F_3 < 0 ) {
F_3 ( L_5 , V_13 , F_3 ) ;
goto V_25;
}
F_16 ( 250 ) ;
for ( V_20 = ( const struct V_19 * ) V_18 -> V_4 ;
V_20 ; V_20 = F_15 ( V_20 ) ) {
if ( ! F_17 ( F_13 ( V_20 -> V_22 ) ) ) {
F_3 = F_1 ( V_2 , F_13 ( V_20 -> V_22 ) ,
V_20 -> V_4 , F_14 ( V_20 -> V_28 ) ,
V_31 ) ;
if ( F_3 < 0 ) {
F_3 ( L_5 , V_13 , F_3 ) ;
goto V_25;
}
}
}
F_3 = F_7 ( V_2 , 1 ) ;
if ( F_3 < 0 ) {
F_3 ( L_5 , V_13 , F_3 ) ;
goto V_25;
}
for ( V_20 = ( const struct V_19 * ) V_18 -> V_4 ;
V_20 ; V_20 = F_15 ( V_20 ) ) {
if ( F_17 ( F_13 ( V_20 -> V_22 ) ) ) {
F_3 = F_1 ( V_2 , F_13 ( V_20 -> V_22 ) ,
V_20 -> V_4 , F_14 ( V_20 -> V_28 ) ,
V_31 ) ;
if ( F_3 < 0 ) {
F_3 ( L_5 , V_13 , F_3 ) ;
goto V_25;
}
}
}
F_3 = F_7 ( V_2 , 0 ) ;
if ( F_3 < 0 ) {
F_3 ( L_5 , V_13 , F_3 ) ;
goto V_25;
}
F_16 ( 250 ) ;
F_18 ( V_16 ) ;
F_18 ( V_17 ) ;
F_18 ( V_18 ) ;
F_6 ( V_23 ) ;
return 1 ;
V_25:
F_18 ( V_16 ) ;
F_18 ( V_17 ) ;
F_18 ( V_18 ) ;
F_6 ( V_23 ) ;
F_19 ( & V_2 -> V_2 , L_9 ) ;
return F_3 ;
}
static int F_20 ( struct V_32 * V_33 , const struct V_34 * V_35 )
{
struct V_1 * V_2 = F_21 ( V_33 ) ;
F_10 ( & V_33 -> V_2 , L_10 ) ;
F_8 ( & V_33 -> V_2 , L_11 , V_13 ) ;
F_9 ( V_2 ) ;
return - V_36 ;
}
static void F_22 ( struct V_32 * V_33 )
{
}
