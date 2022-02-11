static void T_1 F_1 ( const char * V_1 , const T_2 * V_2 , int V_3 )
{
F_2 ( L_1 , V_1 ) ;
while( V_3 -- )
F_3 ( L_2 , * ( V_2 ++ ) ) ;
F_2 ( L_3 ) ;
}
static void T_1 F_1 ( const char * V_1 , const T_2 * V_2 , int V_3 ) { }
static void T_1 F_4 ( const void * V_4 , int V_5 ,
int * V_6 , int * V_7 )
{
const T_2 * V_8 ;
if ( V_6 ) {
V_8 = F_5 ( V_4 , V_5 , L_4 , NULL ) ;
if ( V_8 )
* V_6 = F_6 ( V_8 ) ;
else
* V_6 = V_9 ;
}
if ( V_7 ) {
V_8 = F_5 ( V_4 , V_5 , L_5 , NULL ) ;
if ( V_8 )
* V_7 = F_6 ( V_8 ) ;
else
* V_7 = V_10 ;
}
}
static T_3 T_1 F_7 ( T_2 * V_2 , const T_2 * V_11 ,
int V_3 , int V_12 , int V_13 )
{
T_3 V_14 , V_1 , V_15 ;
V_14 = F_8 ( V_11 , V_3 ) ;
V_1 = F_8 ( V_11 + V_3 + V_13 , V_12 ) ;
V_15 = F_8 ( V_2 , V_3 ) ;
F_2 ( L_6 ,
V_14 , V_1 , V_15 ) ;
if ( V_15 < V_14 || V_15 >= ( V_14 + V_1 ) )
return V_16 ;
return V_15 - V_14 ;
}
static int T_1 F_9 ( T_2 * V_2 , T_3 V_17 , int V_3 )
{
T_3 V_18 = F_8 ( V_2 , V_3 ) ;
memset ( V_2 , 0 , V_3 * 4 ) ;
V_18 += V_17 ;
if ( V_3 > 1 )
V_2 [ V_3 - 2 ] = F_10 ( V_18 >> 32 ) ;
V_2 [ V_3 - 1 ] = F_10 ( V_18 & 0xffffffffu ) ;
return 0 ;
}
static int T_1 F_11 ( const void * V_4 , int V_19 ,
const struct V_20 * V_21 ,
const struct V_20 * V_22 , T_2 * V_2 ,
int V_3 , int V_12 , int V_13 , const char * V_23 )
{
const T_2 * V_24 ;
int V_25 ;
int V_26 ;
T_3 V_17 = V_16 ;
V_24 = F_5 ( V_4 , V_19 , V_23 , & V_25 ) ;
if ( ! V_24 )
return 1 ;
if ( V_25 == 0 ) {
V_17 = F_8 ( V_2 , V_3 ) ;
memset ( V_2 , 0 , V_13 * 4 ) ;
F_2 ( L_7 ) ;
goto V_27;
}
F_2 ( L_8 ) ;
V_25 /= 4 ;
V_26 = V_3 + V_13 + V_12 ;
for (; V_25 >= V_26 ; V_25 -= V_26 , V_24 += V_26 ) {
V_17 = V_21 -> V_28 ( V_2 , V_24 , V_3 , V_12 , V_13 ) ;
if ( V_17 != V_16 )
break;
}
if ( V_17 == V_16 ) {
F_2 ( L_9 ) ;
return 1 ;
}
memcpy ( V_2 , V_24 + V_3 , 4 * V_13 ) ;
V_27:
F_1 ( L_10 , V_2 , V_13 ) ;
F_2 ( L_11 , V_17 ) ;
return V_22 -> V_29 ( V_2 , V_17 , V_13 ) ;
}
T_3 T_1 F_12 ( const void * V_4 , int V_30 )
{
int V_19 , V_31 ;
const struct V_20 * V_21 , * V_22 ;
const T_2 * V_32 ;
T_2 V_2 [ V_33 ] ;
int V_3 , V_12 , V_13 , V_34 ;
T_3 V_35 = V_16 ;
F_2 ( L_12 ,
F_13 ( V_4 , V_30 , NULL ) ) ;
V_32 = F_5 ( V_4 , V_30 , L_13 , & V_31 ) ;
if ( ! V_32 ) {
F_14 ( L_14 ,
F_13 ( V_4 , V_30 , NULL ) ) ;
goto V_36;
}
V_19 = F_15 ( V_4 , V_30 ) ;
if ( V_19 < 0 )
goto V_36;
V_21 = & V_37 [ 0 ] ;
V_21 -> V_38 ( V_4 , V_19 , & V_3 , & V_12 ) ;
if ( ! F_16 ( V_3 , V_12 ) ) {
F_14 ( L_15 ,
F_13 ( V_4 , V_30 , NULL ) ) ;
goto V_36;
}
memcpy ( V_2 , V_32 , V_3 * 4 ) ;
F_2 ( L_16 ,
V_3 , V_12 , F_13 ( V_4 , V_19 , NULL ) ) ;
F_1 ( L_17 , V_2 , V_3 ) ;
for (; ; ) {
V_30 = V_19 ;
V_19 = F_15 ( V_4 , V_30 ) ;
if ( V_19 < 0 ) {
F_2 ( L_18 ) ;
V_35 = F_8 ( V_2 , V_3 ) ;
break;
}
V_22 = & V_37 [ 0 ] ;
V_22 -> V_38 ( V_4 , V_19 , & V_13 , & V_34 ) ;
if ( ! F_16 ( V_13 , V_34 ) ) {
F_14 ( L_15 ,
F_13 ( V_4 , V_30 , NULL ) ) ;
break;
}
F_2 ( L_19 ,
V_13 , V_34 , F_13 ( V_4 , V_19 , NULL ) ) ;
if ( F_11 ( V_4 , V_30 , V_21 , V_22 ,
V_2 , V_3 , V_12 , V_13 , L_20 ) )
break;
V_3 = V_13 ;
V_12 = V_34 ;
V_21 = V_22 ;
F_1 ( L_21 , V_2 , V_3 ) ;
}
V_36:
return V_35 ;
}
