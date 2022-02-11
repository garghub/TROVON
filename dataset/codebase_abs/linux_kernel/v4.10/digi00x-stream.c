int F_1 ( struct V_1 * V_2 , unsigned int * V_3 )
{
T_1 V_4 ;
T_2 V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_8 ,
V_9 + V_10 ,
& V_5 , sizeof( V_5 ) , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 = F_3 ( V_5 ) & 0x0f ;
if ( V_4 < F_4 ( V_11 ) )
* V_3 = V_11 [ V_4 ] ;
else
V_6 = - V_12 ;
return V_6 ;
}
int F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_2 V_5 ;
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < F_4 ( V_11 ) ; V_13 ++ ) {
if ( V_3 == V_11 [ V_13 ] )
break;
}
if ( V_13 == F_4 ( V_11 ) )
return - V_14 ;
V_5 = F_6 ( V_13 ) ;
return F_2 ( V_2 -> V_7 , V_15 ,
V_9 + V_10 ,
& V_5 , sizeof( V_5 ) , 0 ) ;
}
int F_7 ( struct V_1 * V_2 ,
enum V_16 * clock )
{
T_2 V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_8 ,
V_9 + V_17 ,
& V_5 , sizeof( V_5 ) , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
* clock = F_3 ( V_5 ) & 0x0f ;
if ( * clock >= V_18 )
V_6 = - V_12 ;
return V_6 ;
}
int F_8 ( struct V_1 * V_2 , bool * V_19 )
{
T_2 V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_8 ,
V_9 + V_20 ,
& V_5 , sizeof( V_5 ) , 0 ) ;
if ( V_6 >= 0 )
* V_19 = F_3 ( V_5 ) > 0 ;
return V_6 ;
}
int F_9 ( struct V_1 * V_2 ,
unsigned int * V_3 )
{
T_1 V_4 ;
T_2 V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_8 ,
V_9 + V_21 ,
& V_5 , sizeof( V_5 ) , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 = F_3 ( V_5 ) & 0x0f ;
if ( V_4 < F_4 ( V_11 ) )
* V_3 = V_11 [ V_4 ] ;
else
V_6 = - V_22 ;
return V_6 ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_2 V_4 = F_6 ( 0x00000003 ) ;
F_2 ( V_2 -> V_7 , V_15 ,
V_9 + V_23 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_2 V_4 ;
T_1 V_24 ;
int V_6 ;
V_6 = F_2 ( V_2 -> V_7 , V_8 ,
V_9 + V_25 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
if ( V_6 < 0 )
goto error;
V_24 = F_3 ( V_4 ) ;
if ( V_24 == 0 )
V_24 = 2 ;
V_24 -- ;
while ( V_24 > 0 ) {
V_4 = F_6 ( V_24 ) ;
V_6 = F_2 ( V_2 -> V_7 ,
V_15 ,
V_9 +
V_23 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
if ( V_6 < 0 )
goto error;
F_12 ( 20 ) ;
V_24 -- ;
}
return 0 ;
error:
F_10 ( V_2 ) ;
return V_6 ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_2 V_4 = 0 ;
F_2 ( V_2 -> V_7 , V_15 ,
V_9 + V_26 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
F_14 ( & V_2 -> V_27 ) ;
F_14 ( & V_2 -> V_28 ) ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned int V_13 ;
T_2 V_4 ;
int V_6 ;
for ( V_13 = 0 ; V_13 < V_29 ; V_13 ++ ) {
if ( V_11 [ V_13 ] == V_3 )
break;
}
if ( V_13 == V_29 )
return - V_14 ;
V_6 = F_16 ( & V_2 -> V_30 , V_3 ,
V_31 [ V_13 ] ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_17 ( & V_2 -> V_28 ,
F_18 ( & V_2 -> V_30 ) ,
F_19 ( V_2 -> V_7 ) -> V_32 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_16 ( & V_2 -> V_33 , V_3 ,
V_31 [ V_13 ] ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_17 ( & V_2 -> V_27 ,
F_18 ( & V_2 -> V_33 ) ,
F_19 ( V_2 -> V_7 ) -> V_32 ) ;
if ( V_6 < 0 )
goto error;
V_4 = F_6 ( ( V_2 -> V_27 . V_34 << 16 ) |
V_2 -> V_28 . V_34 ) ;
V_6 = F_2 ( V_2 -> V_7 , V_15 ,
V_9 + V_26 ,
& V_4 , sizeof( V_4 ) , 0 ) ;
if ( V_6 < 0 )
goto error;
return 0 ;
error:
F_13 ( V_2 ) ;
return V_6 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_21 ( & V_2 -> V_28 , V_2 -> V_7 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_22 ( & V_2 -> V_30 , V_2 -> V_7 , V_35 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_21 ( & V_2 -> V_27 , V_2 -> V_7 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_22 ( & V_2 -> V_33 , V_2 -> V_7 , V_36 ) ;
if ( V_6 < 0 )
goto error;
return 0 ;
error:
F_23 ( V_2 ) ;
return V_6 ;
}
void F_23 ( struct V_1 * V_2 )
{
F_24 ( & V_2 -> V_30 ) ;
F_25 ( & V_2 -> V_28 ) ;
F_24 ( & V_2 -> V_33 ) ;
F_25 ( & V_2 -> V_27 ) ;
}
int F_26 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned int V_37 ;
int V_6 = 0 ;
if ( V_2 -> V_38 == 0 )
goto V_39;
V_6 = F_1 ( V_2 , & V_37 ) ;
if ( V_6 < 0 )
goto error;
if ( V_3 == 0 )
V_3 = V_37 ;
if ( V_37 != V_3 ||
F_27 ( & V_2 -> V_33 ) ||
F_27 ( & V_2 -> V_30 ) ) {
F_10 ( V_2 ) ;
F_28 ( & V_2 -> V_33 ) ;
F_28 ( & V_2 -> V_30 ) ;
F_13 ( V_2 ) ;
}
if ( ! F_29 ( & V_2 -> V_30 ) ) {
V_6 = F_5 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_15 ( V_2 , V_3 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_11 ( V_2 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_30 ( & V_2 -> V_30 ,
V_2 -> V_28 . V_34 ,
F_19 ( V_2 -> V_7 ) -> V_32 ) ;
if ( V_6 < 0 )
goto error;
if ( ! F_31 ( & V_2 -> V_30 ,
V_40 ) ) {
V_6 = - V_41 ;
goto error;
}
}
if ( ! F_29 ( & V_2 -> V_33 ) ) {
V_6 = F_30 ( & V_2 -> V_33 ,
V_2 -> V_27 . V_34 ,
F_19 ( V_2 -> V_7 ) -> V_32 ) ;
if ( V_6 < 0 )
goto error;
if ( ! F_31 ( & V_2 -> V_33 ,
V_40 ) ) {
V_6 = - V_41 ;
goto error;
}
}
V_39:
return V_6 ;
error:
F_10 ( V_2 ) ;
F_28 ( & V_2 -> V_33 ) ;
F_28 ( & V_2 -> V_30 ) ;
F_13 ( V_2 ) ;
return V_6 ;
}
void F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 > 0 )
return;
F_28 ( & V_2 -> V_33 ) ;
F_28 ( & V_2 -> V_30 ) ;
F_10 ( V_2 ) ;
F_13 ( V_2 ) ;
F_12 ( 50 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
F_34 ( & V_2 -> V_27 ) ;
F_34 ( & V_2 -> V_28 ) ;
F_35 ( & V_2 -> V_33 ) ;
F_35 ( & V_2 -> V_30 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
V_2 -> V_42 = true ;
F_37 ( & V_2 -> V_43 ) ;
}
int F_38 ( struct V_1 * V_2 )
{
int V_6 ;
F_39 ( & V_2 -> V_44 ) ;
if ( V_2 -> V_45 < 0 ) {
V_6 = - V_22 ;
goto V_39;
}
if ( V_2 -> V_45 ++ == 0 )
F_36 ( V_2 ) ;
V_6 = 0 ;
V_39:
F_40 ( & V_2 -> V_44 ) ;
return V_6 ;
}
void F_41 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_44 ) ;
if ( F_42 ( V_2 -> V_45 <= 0 ) )
goto V_39;
if ( -- V_2 -> V_45 == 0 )
F_36 ( V_2 ) ;
V_39:
F_40 ( & V_2 -> V_44 ) ;
}
