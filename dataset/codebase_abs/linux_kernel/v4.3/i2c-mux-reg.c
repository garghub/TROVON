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
static int F_10 ( struct V_10 * V_11 , void * V_4 ,
unsigned int V_12 )
{
struct V_1 * V_2 = V_4 ;
return F_1 ( V_2 , V_12 ) ;
}
static int F_11 ( struct V_10 * V_11 , void * V_4 ,
unsigned int V_12 )
{
struct V_1 * V_2 = V_4 ;
if ( V_2 -> V_4 . V_13 )
return F_1 ( V_2 , V_2 -> V_4 . V_14 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 . V_20 ;
struct V_17 * V_21 , * V_22 ;
struct V_10 * V_23 ;
struct V_24 V_25 ;
unsigned * V_26 ;
int V_27 = 0 ;
if ( ! V_18 )
return - V_28 ;
V_21 = F_13 ( V_18 , L_1 , 0 ) ;
if ( ! V_21 ) {
F_14 ( & V_16 -> V_19 , L_2 ) ;
return - V_28 ;
}
V_23 = F_15 ( V_21 ) ;
F_16 ( V_21 ) ;
if ( ! V_23 )
return - V_29 ;
V_2 -> V_30 = V_23 ;
V_2 -> V_4 . V_30 = F_17 ( V_23 ) ;
F_18 ( & V_23 -> V_19 ) ;
V_2 -> V_4 . V_31 = F_19 ( V_18 ) ;
if ( F_20 ( V_18 , L_3 , NULL ) ) {
V_2 -> V_4 . V_8 = true ;
} else if ( F_20 ( V_18 , L_4 , NULL ) ) {
V_2 -> V_4 . V_8 = false ;
} else {
#if F_21 ( V_32 ) ? V_32 == V_33 : \
F_21 ( V_33 )
V_2 -> V_4 . V_8 = true ;
#elif F_21 ( V_32 ) ? V_32 == V_34 : \
F_21 ( V_34 )
V_2 -> V_4 . V_8 = false ;
#else
#error Endianness not defined?
#endif
}
if ( F_20 ( V_18 , L_5 , NULL ) )
V_2 -> V_4 . V_9 = true ;
else
V_2 -> V_4 . V_9 = false ;
V_26 = F_22 ( & V_16 -> V_19 ,
sizeof( * V_2 -> V_4 . V_26 ) * V_2 -> V_4 . V_31 ,
V_35 ) ;
if ( ! V_26 ) {
F_14 ( & V_16 -> V_19 , L_6 ) ;
return - V_36 ;
}
F_23 (np, child) {
F_24 ( V_22 , L_7 , V_26 + V_27 ) ;
V_27 ++ ;
}
V_2 -> V_4 . V_26 = V_26 ;
if ( ! F_24 ( V_18 , L_8 , & V_2 -> V_4 . V_14 ) )
V_2 -> V_4 . V_13 = true ;
if ( F_25 ( V_18 , 0 , & V_25 ) ) {
V_2 -> V_4 . V_7 = F_26 ( & V_25 ) ;
V_2 -> V_4 . V_5 = F_27 ( & V_16 -> V_19 , & V_25 ) ;
if ( F_28 ( V_2 -> V_4 . V_5 ) )
return F_29 ( V_2 -> V_4 . V_5 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
return 0 ;
}
static int F_30 ( struct V_15 * V_16 )
{
struct V_1 * V_2 ;
struct V_10 * V_30 ;
struct V_24 * V_25 ;
int (* F_31)( struct V_10 * , void * , T_1 );
unsigned int V_37 ;
int V_27 , V_38 , V_39 ;
V_2 = F_22 ( & V_16 -> V_19 , sizeof( * V_2 ) , V_35 ) ;
if ( ! V_2 )
return - V_36 ;
F_32 ( V_16 , V_2 ) ;
if ( F_33 ( & V_16 -> V_19 ) ) {
memcpy ( & V_2 -> V_4 , F_33 ( & V_16 -> V_19 ) ,
sizeof( V_2 -> V_4 ) ) ;
V_30 = F_34 ( V_2 -> V_4 . V_30 ) ;
if ( ! V_30 )
return - V_29 ;
V_2 -> V_30 = V_30 ;
} else {
V_38 = F_12 ( V_2 , V_16 ) ;
if ( V_38 < 0 ) {
F_14 ( & V_16 -> V_19 , L_9 ) ;
return V_38 ;
}
}
if ( ! V_2 -> V_4 . V_5 ) {
F_35 ( & V_16 -> V_19 ,
L_10 ) ;
V_25 = F_36 ( V_16 , V_40 , 0 ) ;
V_2 -> V_4 . V_7 = F_26 ( V_25 ) ;
V_2 -> V_4 . V_5 = F_27 ( & V_16 -> V_19 , V_25 ) ;
if ( F_28 ( V_2 -> V_4 . V_5 ) )
return F_29 ( V_2 -> V_4 . V_5 ) ;
}
if ( V_2 -> V_4 . V_7 != 4 && V_2 -> V_4 . V_7 != 2 &&
V_2 -> V_4 . V_7 != 1 ) {
F_14 ( & V_16 -> V_19 , L_11 ) ;
return - V_6 ;
}
V_2 -> V_11 = F_22 ( & V_16 -> V_19 ,
sizeof( * V_2 -> V_11 ) * V_2 -> V_4 . V_31 ,
V_35 ) ;
if ( ! V_2 -> V_11 ) {
F_14 ( & V_16 -> V_19 , L_12 ) ;
return - V_36 ;
}
if ( V_2 -> V_4 . V_13 )
F_31 = F_11 ;
else
F_31 = NULL ;
for ( V_27 = 0 ; V_27 < V_2 -> V_4 . V_31 ; V_27 ++ ) {
V_39 = V_2 -> V_4 . V_41 ? ( V_2 -> V_4 . V_41 + V_27 ) : 0 ;
V_37 = V_2 -> V_4 . V_42 ? V_2 -> V_4 . V_42 [ V_27 ] : 0 ;
V_2 -> V_11 [ V_27 ] = F_37 ( V_2 -> V_30 , & V_16 -> V_19 , V_2 ,
V_39 , V_2 -> V_4 . V_26 [ V_27 ] ,
V_37 , F_10 ,
F_31 ) ;
if ( ! V_2 -> V_11 [ V_27 ] ) {
V_38 = - V_28 ;
F_14 ( & V_16 -> V_19 , L_13 , V_27 ) ;
goto V_43;
}
}
F_38 ( & V_16 -> V_19 , L_14 ,
V_2 -> V_4 . V_31 , V_2 -> V_30 -> V_44 ) ;
return 0 ;
V_43:
for (; V_27 > 0 ; V_27 -- )
F_39 ( V_2 -> V_11 [ V_27 - 1 ] ) ;
return V_38 ;
}
static int F_40 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_41 ( V_16 ) ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_4 . V_31 ; V_27 ++ )
F_39 ( V_2 -> V_11 [ V_27 ] ) ;
F_42 ( V_2 -> V_30 ) ;
return 0 ;
}
