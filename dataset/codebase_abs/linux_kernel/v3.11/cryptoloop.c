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
struct V_33 V_34 = {
. V_15 = V_15 ,
. V_35 = V_36 ,
} ;
struct V_37 V_38 ;
struct V_37 V_39 ;
T_2 V_40 ;
struct V_26 * V_41 , * V_42 ;
unsigned V_43 , V_44 ;
int V_5 ;
F_8 ( & V_38 , 1 ) ;
F_8 ( & V_39 , 1 ) ;
if ( V_25 == V_45 ) {
V_41 = V_27 ;
V_43 = V_28 ;
V_42 = V_29 ;
V_44 = V_30 ;
V_40 = F_9 ( V_15 ) -> V_46 ;
} else {
V_41 = V_29 ;
V_43 = V_30 ;
V_42 = V_27 ;
V_44 = V_28 ;
V_40 = F_9 ( V_15 ) -> V_47 ;
}
while ( V_31 > 0 ) {
const int V_48 = F_10 ( V_31 , V_17 ) ;
T_3 V_49 [ 4 ] = { 0 , } ;
V_49 [ 0 ] = F_11 ( V_32 & 0xffffffff ) ;
F_12 ( & V_39 , V_41 , V_48 , V_43 ) ;
F_12 ( & V_38 , V_42 , V_48 , V_44 ) ;
V_34 . V_4 = V_49 ;
V_5 = V_40 ( & V_34 , & V_38 , & V_39 , V_48 ) ;
if ( V_5 )
return V_5 ;
V_32 ++ ;
V_31 -= V_48 ;
V_43 += V_48 ;
V_44 += V_48 ;
}
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 , int V_25 , unsigned long V_50 )
{
return - V_6 ;
}
static int
F_14 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_24 ;
if ( V_15 != NULL ) {
F_6 ( V_15 ) ;
V_2 -> V_24 = NULL ;
return 0 ;
}
F_15 ( V_51 L_3 ) ;
return - V_6 ;
}
static int T_4
F_16 ( void )
{
int V_52 = F_17 ( & V_53 ) ;
if ( V_52 )
F_15 ( V_51 L_4 ) ;
return V_52 ;
}
static void T_5
F_18 ( void )
{
if ( F_19 ( V_54 ) )
F_15 ( V_51
L_5 ) ;
}
