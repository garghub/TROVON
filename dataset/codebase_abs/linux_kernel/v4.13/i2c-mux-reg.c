static int F_1 ( const struct V_1 * V_2 , unsigned int V_3 )
{
if ( ! V_2 -> V_4 . V_5 )
return - V_6 ;
switch ( V_2 -> V_4 . V_7 ) {
case 4 :
if ( V_2 -> V_4 . V_8 )
F_2 ( V_3 , V_2 -> V_4 . V_5 ) ;
else
F_3 ( V_3 , V_2 -> V_4 . V_5 ) ;
if ( ! V_2 -> V_4 . V_9 )
F_4 ( V_2 -> V_4 . V_5 ) ;
break;
case 2 :
if ( V_2 -> V_4 . V_8 )
F_5 ( V_3 , V_2 -> V_4 . V_5 ) ;
else
F_6 ( V_3 , V_2 -> V_4 . V_5 ) ;
if ( ! V_2 -> V_4 . V_9 )
F_7 ( V_2 -> V_4 . V_5 ) ;
break;
case 1 :
F_8 ( V_3 , V_2 -> V_4 . V_5 ) ;
if ( ! V_2 -> V_4 . V_9 )
F_9 ( V_2 -> V_4 . V_5 ) ;
break;
}
return 0 ;
}
static int F_10 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
return F_1 ( V_2 , V_12 ) ;
}
static int F_12 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_1 * V_2 = F_11 ( V_11 ) ;
if ( V_2 -> V_4 . V_13 )
return F_1 ( V_2 , V_2 -> V_4 . V_14 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 . V_20 ;
struct V_17 * V_21 , * V_22 ;
struct V_23 * V_24 ;
struct V_25 V_26 ;
unsigned * V_27 ;
int V_28 = 0 ;
if ( ! V_18 )
return - V_29 ;
V_21 = F_14 ( V_18 , L_1 , 0 ) ;
if ( ! V_21 ) {
F_15 ( & V_16 -> V_19 , L_2 ) ;
return - V_29 ;
}
V_24 = F_16 ( V_21 ) ;
F_17 ( V_21 ) ;
if ( ! V_24 )
return - V_30 ;
V_2 -> V_4 . V_31 = F_18 ( V_24 ) ;
F_19 ( & V_24 -> V_19 ) ;
V_2 -> V_4 . V_32 = F_20 ( V_18 ) ;
if ( F_21 ( V_18 , L_3 , NULL ) ) {
V_2 -> V_4 . V_8 = true ;
} else if ( F_21 ( V_18 , L_4 , NULL ) ) {
V_2 -> V_4 . V_8 = false ;
} else {
#if F_22 ( V_33 ) ? V_33 == V_34 : \
F_22 ( V_34 )
V_2 -> V_4 . V_8 = true ;
#elif F_22 ( V_33 ) ? V_33 == V_35 : \
F_22 ( V_35 )
V_2 -> V_4 . V_8 = false ;
#else
#error Endianness not defined?
#endif
}
if ( F_21 ( V_18 , L_5 , NULL ) )
V_2 -> V_4 . V_9 = true ;
else
V_2 -> V_4 . V_9 = false ;
V_27 = F_23 ( & V_16 -> V_19 ,
sizeof( * V_2 -> V_4 . V_27 ) * V_2 -> V_4 . V_32 ,
V_36 ) ;
if ( ! V_27 ) {
F_15 ( & V_16 -> V_19 , L_6 ) ;
return - V_37 ;
}
F_24 (np, child) {
F_25 ( V_22 , L_7 , V_27 + V_28 ) ;
V_28 ++ ;
}
V_2 -> V_4 . V_27 = V_27 ;
if ( ! F_25 ( V_18 , L_8 , & V_2 -> V_4 . V_14 ) )
V_2 -> V_4 . V_13 = true ;
if ( F_26 ( V_18 , 0 , & V_26 ) == 0 ) {
V_2 -> V_4 . V_7 = F_27 ( & V_26 ) ;
V_2 -> V_4 . V_5 = F_28 ( & V_16 -> V_19 , & V_26 ) ;
if ( F_29 ( V_2 -> V_4 . V_5 ) )
return F_30 ( V_2 -> V_4 . V_5 ) ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
return 0 ;
}
static int F_31 ( struct V_15 * V_16 )
{
struct V_10 * V_11 ;
struct V_1 * V_2 ;
struct V_23 * V_31 ;
struct V_25 * V_26 ;
unsigned int V_38 ;
int V_28 , V_39 , V_40 ;
V_2 = F_23 ( & V_16 -> V_19 , sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return - V_37 ;
if ( F_32 ( & V_16 -> V_19 ) ) {
memcpy ( & V_2 -> V_4 , F_32 ( & V_16 -> V_19 ) ,
sizeof( V_2 -> V_4 ) ) ;
} else {
V_39 = F_13 ( V_2 , V_16 ) ;
if ( V_39 < 0 ) {
F_15 ( & V_16 -> V_19 , L_9 ) ;
return V_39 ;
}
}
V_31 = F_33 ( V_2 -> V_4 . V_31 ) ;
if ( ! V_31 )
return - V_30 ;
if ( ! V_2 -> V_4 . V_5 ) {
F_34 ( & V_16 -> V_19 ,
L_10 ) ;
V_26 = F_35 ( V_16 , V_41 , 0 ) ;
V_2 -> V_4 . V_7 = F_27 ( V_26 ) ;
V_2 -> V_4 . V_5 = F_28 ( & V_16 -> V_19 , V_26 ) ;
if ( F_29 ( V_2 -> V_4 . V_5 ) ) {
V_39 = F_30 ( V_2 -> V_4 . V_5 ) ;
goto V_42;
}
}
if ( V_2 -> V_4 . V_7 != 4 && V_2 -> V_4 . V_7 != 2 &&
V_2 -> V_4 . V_7 != 1 ) {
F_15 ( & V_16 -> V_19 , L_11 ) ;
V_39 = - V_6 ;
goto V_42;
}
V_11 = F_36 ( V_31 , & V_16 -> V_19 , V_2 -> V_4 . V_32 , 0 , 0 ,
F_10 , NULL ) ;
if ( ! V_11 ) {
V_39 = - V_37 ;
goto V_42;
}
V_11 -> V_43 = V_2 ;
F_37 ( V_16 , V_11 ) ;
if ( V_2 -> V_4 . V_13 )
V_11 -> V_44 = F_12 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_4 . V_32 ; V_28 ++ ) {
V_40 = V_2 -> V_4 . V_45 ? ( V_2 -> V_4 . V_45 + V_28 ) : 0 ;
V_38 = V_2 -> V_4 . V_46 ? V_2 -> V_4 . V_46 [ V_28 ] : 0 ;
V_39 = F_38 ( V_11 , V_40 , V_2 -> V_4 . V_27 [ V_28 ] , V_38 ) ;
if ( V_39 )
goto V_47;
}
F_39 ( & V_16 -> V_19 , L_12 ,
V_2 -> V_4 . V_32 , V_11 -> V_31 -> V_48 ) ;
return 0 ;
V_47:
F_40 ( V_11 ) ;
V_42:
F_41 ( V_31 ) ;
return V_39 ;
}
static int F_42 ( struct V_15 * V_16 )
{
struct V_10 * V_11 = F_43 ( V_16 ) ;
F_40 ( V_11 ) ;
F_41 ( V_11 -> V_31 ) ;
return 0 ;
}
