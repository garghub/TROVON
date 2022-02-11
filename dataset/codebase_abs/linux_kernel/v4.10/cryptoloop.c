static int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
int V_5 = - V_6 ;
int V_7 ;
int V_8 ;
char V_9 [ V_10 ] ;
char * V_11 ;
char * V_12 ;
char * V_13 = V_9 ;
struct V_14 * V_15 ;
if ( V_4 -> V_16 % V_17 )
goto V_18;
strncpy ( V_9 , V_4 -> V_19 , V_10 ) ;
V_9 [ V_10 - 1 ] = 0 ;
V_11 = V_13 ;
V_7 = strcspn ( V_13 , L_1 ) ;
V_12 = V_13 + V_7 ;
V_8 = 0 ;
if ( * V_12 ) {
V_12 ++ ;
V_8 = strcspn ( V_12 , L_1 ) ;
}
if ( ! V_8 ) {
V_12 = L_2 ;
V_8 = 3 ;
}
if ( V_7 + V_8 + 3 > V_10 )
return - V_6 ;
memmove ( V_9 , V_12 , V_8 ) ;
V_13 = V_9 + V_8 ;
* V_13 ++ = '(' ;
memcpy ( V_13 , V_4 -> V_19 , V_7 ) ;
V_13 += V_7 ;
* V_13 ++ = ')' ;
* V_13 = 0 ;
V_15 = F_2 ( V_9 , 0 , V_20 ) ;
if ( F_3 ( V_15 ) )
return F_4 ( V_15 ) ;
V_5 = F_5 ( V_15 , V_4 -> V_21 ,
V_4 -> V_22 ) ;
if ( V_5 != 0 )
goto V_23;
V_2 -> V_24 = V_15 ;
return 0 ;
V_23:
F_6 ( V_15 ) ;
V_18:
return V_5 ;
}
static int
F_7 ( struct V_1 * V_2 , int V_25 ,
struct V_26 * V_27 , unsigned V_28 ,
struct V_26 * V_29 , unsigned V_30 ,
int V_31 , T_1 V_32 )
{
struct V_14 * V_15 = V_2 -> V_24 ;
F_8 ( V_33 , V_15 ) ;
struct V_34 V_35 ;
struct V_34 V_36 ;
T_2 V_37 ;
struct V_26 * V_38 , * V_39 ;
unsigned V_40 , V_41 ;
int V_5 ;
F_9 ( V_33 , V_15 ) ;
F_10 ( V_33 , V_42 ,
NULL , NULL ) ;
F_11 ( & V_35 , 1 ) ;
F_11 ( & V_36 , 1 ) ;
if ( V_25 == V_43 ) {
V_38 = V_27 ;
V_40 = V_28 ;
V_39 = V_29 ;
V_41 = V_30 ;
V_37 = V_44 ;
} else {
V_38 = V_29 ;
V_40 = V_30 ;
V_39 = V_27 ;
V_41 = V_28 ;
V_37 = V_45 ;
}
while ( V_31 > 0 ) {
const int V_46 = F_12 ( V_31 , V_17 ) ;
T_3 V_47 [ 4 ] = { 0 , } ;
V_47 [ 0 ] = F_13 ( V_32 & 0xffffffff ) ;
F_14 ( & V_36 , V_38 , V_46 , V_40 ) ;
F_14 ( & V_35 , V_39 , V_46 , V_41 ) ;
F_15 ( V_33 , & V_36 , & V_35 , V_46 , V_47 ) ;
V_5 = V_37 ( V_33 ) ;
if ( V_5 )
goto V_18;
V_32 ++ ;
V_31 -= V_46 ;
V_40 += V_46 ;
V_41 += V_46 ;
}
V_5 = 0 ;
V_18:
F_16 ( V_33 ) ;
return V_5 ;
}
static int
F_17 ( struct V_1 * V_2 , int V_25 , unsigned long V_48 )
{
return - V_6 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_24 ;
if ( V_15 != NULL ) {
F_6 ( V_15 ) ;
V_2 -> V_24 = NULL ;
return 0 ;
}
F_19 ( V_49 L_3 ) ;
return - V_6 ;
}
static int T_4
F_20 ( void )
{
int V_50 = F_21 ( & V_51 ) ;
if ( V_50 )
F_19 ( V_49 L_4 ) ;
return V_50 ;
}
static void T_5
F_22 ( void )
{
if ( F_23 ( V_52 ) )
F_19 ( V_49
L_5 ) ;
}
