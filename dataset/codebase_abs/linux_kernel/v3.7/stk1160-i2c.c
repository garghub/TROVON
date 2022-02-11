static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
V_4 = V_6 + F_2 ( V_7 ) ;
while ( F_3 ( V_4 ) ) {
F_4 ( V_2 , V_8 + 1 , & V_5 ) ;
if ( V_5 & V_3 )
goto V_9;
F_5 ( 10 * V_10 , 20 * V_10 ) ;
}
return - V_11 ;
V_9:
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
int V_15 ;
V_15 = F_7 ( V_2 , V_16 , V_12 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_7 ( V_2 , V_17 , V_13 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_7 ( V_2 , V_18 , V_14 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_7 ( V_2 , V_8 , 0x01 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_1 ( V_2 , 0x04 ) ;
if ( V_15 < 0 )
return V_15 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_12 ,
T_1 V_13 , T_1 * V_14 )
{
int V_15 ;
V_15 = F_7 ( V_2 , V_16 , V_12 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_7 ( V_2 , V_19 , V_13 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_7 ( V_2 , V_8 , 0x20 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_1 ( V_2 , 0x01 ) ;
if ( V_15 < 0 )
return V_15 ;
F_4 ( V_2 , V_20 , V_14 ) ;
if ( V_15 < 0 )
return V_15 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned char V_12 )
{
int V_15 ;
V_15 = F_7 ( V_2 , V_16 , V_12 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_7 ( V_2 , V_19 , 0x00 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_7 ( V_2 , V_8 , 0x20 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_1 ( V_2 , 0x01 ) ;
if ( V_15 < 0 )
return - V_21 ;
return 0 ;
}
static int F_10 ( struct V_22 * V_23 ,
struct V_24 V_25 [] , int V_26 )
{
struct V_1 * V_2 = V_23 -> V_27 ;
int V_12 , V_15 , V_28 ;
for ( V_28 = 0 ; V_28 < V_26 ; V_28 ++ ) {
V_12 = V_25 [ V_28 ] . V_12 << 1 ;
F_11 ( L_1 , V_29 , V_12 ) ;
if ( ! V_25 [ V_28 ] . V_30 ) {
V_15 = F_9 ( V_2 , V_12 ) ;
if ( V_15 < 0 ) {
F_11 ( L_2 ) ;
return V_15 ;
}
} else if ( V_25 [ V_28 ] . V_31 & V_32 ) {
F_11 ( L_3 ) ;
V_15 = - V_33 ;
goto V_34;
} else if ( V_28 + 1 < V_26 && V_25 [ V_28 ] . V_30 <= 2 &&
( V_25 [ V_28 + 1 ] . V_31 & V_32 ) &&
V_25 [ V_28 ] . V_12 == V_25 [ V_28 + 1 ] . V_12 ) {
if ( V_25 [ V_28 ] . V_30 != 1 || V_25 [ V_28 + 1 ] . V_30 != 1 ) {
F_11 ( L_4 ) ;
V_15 = - V_33 ;
goto V_34;
}
F_11 ( L_5 , V_25 [ V_28 ] . V_35 [ 0 ] ) ;
V_15 = F_8 ( V_2 , V_12 , V_25 [ V_28 ] . V_35 [ 0 ] ,
V_25 [ V_28 + 1 ] . V_35 ) ;
F_11 ( L_6 , * V_25 [ V_28 + 1 ] . V_35 ) ;
V_28 ++ ;
} else {
if ( V_25 [ V_28 ] . V_30 != 2 ) {
F_11 ( L_4 ) ;
V_15 = - V_33 ;
goto V_34;
}
F_11 ( L_7 ,
V_25 [ V_28 ] . V_35 [ 0 ] , V_25 [ V_28 ] . V_35 [ 1 ] ) ;
V_15 = F_6 ( V_2 , V_12 , V_25 [ V_28 ] . V_35 [ 0 ] ,
V_25 [ V_28 ] . V_35 [ 1 ] ) ;
}
if ( V_15 < 0 )
goto V_34;
F_11 ( L_8 ) ;
}
return V_26 ;
V_34:
F_11 ( L_9 , V_15 ) ;
return V_26 ;
}
static T_2 F_12 ( struct V_22 * V_36 )
{
return V_37 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_15 ;
V_2 -> V_23 = V_38 ;
V_2 -> V_23 . V_2 . V_39 = V_2 -> V_2 ;
strcpy ( V_2 -> V_23 . V_40 , L_10 ) ;
V_2 -> V_23 . V_27 = V_2 ;
F_14 ( & V_2 -> V_23 , & V_2 -> V_41 ) ;
V_15 = F_15 ( & V_2 -> V_23 ) ;
if ( V_15 < 0 ) {
F_16 ( L_11 , V_15 ) ;
return V_15 ;
}
V_2 -> V_42 = V_43 ;
V_2 -> V_42 . V_44 = & V_2 -> V_23 ;
F_7 ( V_2 , V_45 , 0x0f ) ;
F_7 ( V_2 , V_46 + 3 , 0x00 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_23 ) ;
return 0 ;
}
