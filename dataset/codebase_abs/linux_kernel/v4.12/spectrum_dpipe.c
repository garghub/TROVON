static int F_1 ( void * V_1 ,
struct V_2 * V_3 )
{
struct V_4 V_5 = { 0 } ;
int V_6 ;
V_5 . type = V_7 ;
V_5 . V_8 = & V_9 ;
V_5 . V_10 = V_11 ;
V_6 = F_2 ( V_3 , & V_5 ) ;
if ( V_6 )
return V_6 ;
V_5 . type = V_7 ;
V_5 . V_8 = & V_9 ;
V_5 . V_10 = V_12 ;
return F_2 ( V_3 , & V_5 ) ;
}
static int F_3 ( void * V_1 ,
struct V_2 * V_3 )
{
struct V_13 V_14 = { 0 } ;
V_14 . type = V_15 ;
V_14 . V_8 = & V_9 ;
V_14 . V_10 = V_16 ;
return F_4 ( V_3 , & V_14 ) ;
}
static void F_5 ( struct V_17 * V_18 )
{
unsigned int V_19 , V_20 ;
struct V_21 * V_22 ;
V_22 = V_18 -> V_23 ;
V_19 = V_18 -> V_24 ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
F_6 ( V_22 [ V_20 ] . V_22 ) ;
F_6 ( V_22 [ V_20 ] . V_25 ) ;
}
V_22 = V_18 -> V_26 ;
V_19 = V_18 -> V_27 ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
F_6 ( V_22 [ V_20 ] . V_22 ) ;
F_6 ( V_22 [ V_20 ] . V_25 ) ;
}
}
static void
F_7 ( struct V_13 * V_14 ,
struct V_4 * V_5 )
{
V_5 -> type = V_7 ;
V_5 -> V_8 = & V_9 ;
V_5 -> V_10 = V_11 ;
V_14 -> type = V_15 ;
V_14 -> V_8 = & V_9 ;
V_14 -> V_10 = V_16 ;
}
static int F_8 ( struct V_17 * V_18 ,
struct V_21 * V_28 ,
struct V_13 * V_14 ,
struct V_21 * V_29 ,
struct V_4 * V_5 )
{
V_18 -> V_26 = V_28 ;
V_18 -> V_27 = 1 ;
V_18 -> V_23 = V_29 ;
V_18 -> V_24 = 1 ;
V_28 -> V_14 = V_14 ;
V_28 -> V_30 = sizeof( V_31 ) ;
V_28 -> V_22 = F_9 ( V_28 -> V_30 , V_32 ) ;
if ( ! V_28 -> V_22 )
return - V_33 ;
V_29 -> V_5 = V_5 ;
V_29 -> V_30 = sizeof( V_31 ) ;
V_29 -> V_22 = F_9 ( V_29 -> V_30 , V_32 ) ;
if ( ! V_29 -> V_22 )
goto V_34;
return 0 ;
V_34:
F_6 ( V_28 -> V_22 ) ;
return - V_33 ;
}
static int F_10 ( struct V_35 * V_35 ,
struct V_17 * V_18 ,
struct V_36 * V_37 ,
bool V_38 )
{
V_31 * V_29 ;
V_31 * V_39 ;
T_1 V_40 ;
int V_6 ;
V_39 = V_18 -> V_26 -> V_22 ;
* V_39 = F_11 ( V_37 ) ;
V_18 -> V_26 -> V_41 = F_12 ( V_37 ) ;
V_18 -> V_26 -> V_42 = true ;
V_29 = V_18 -> V_23 -> V_22 ;
* V_29 = 1 ;
V_18 -> V_43 = false ;
V_18 -> V_44 = 0 ;
V_18 -> V_45 = F_11 ( V_37 ) ;
if ( ! V_38 )
return 0 ;
V_6 = F_13 ( V_35 , V_37 ,
V_46 ,
& V_40 ) ;
if ( ! V_6 ) {
V_18 -> V_44 = V_40 ;
V_18 -> V_43 = true ;
}
return 0 ;
}
static int
F_14 ( void * V_1 , bool V_38 ,
struct V_47 * V_48 )
{
struct V_21 V_28 = { { 0 } } , V_29 = { { 0 } } ;
struct V_4 V_5 = { 0 } ;
struct V_13 V_14 = { 0 } ;
struct V_17 V_18 = { 0 } ;
struct V_35 * V_35 = V_1 ;
unsigned int V_49 ;
int V_50 , V_51 ;
int V_6 ;
F_7 ( & V_14 , & V_5 ) ;
V_6 = F_8 ( & V_18 , & V_28 , & V_14 ,
& V_29 , & V_5 ) ;
if ( V_6 )
return V_6 ;
V_49 = F_15 ( V_35 -> V_52 , V_53 ) ;
F_16 () ;
V_50 = 0 ;
V_54:
V_6 = F_17 ( V_48 ) ;
if ( V_6 )
return V_6 ;
V_51 = 0 ;
for (; V_50 < V_49 ; V_50 ++ ) {
if ( ! V_35 -> V_55 [ V_50 ] )
continue;
V_6 = F_10 ( V_35 , & V_18 ,
V_35 -> V_55 [ V_50 ] ,
V_38 ) ;
if ( V_6 )
goto V_56;
V_6 = F_18 ( V_48 , & V_18 ) ;
if ( V_6 ) {
if ( V_6 == - V_57 ) {
if ( ! V_51 )
goto V_58;
break;
}
goto V_58;
}
V_51 ++ ;
}
F_19 ( V_48 ) ;
if ( V_50 != V_49 )
goto V_54;
F_20 () ;
F_5 ( & V_18 ) ;
return 0 ;
V_58:
V_56:
F_20 () ;
F_5 ( & V_18 ) ;
return V_6 ;
}
static int F_21 ( void * V_1 , bool V_59 )
{
struct V_35 * V_35 = V_1 ;
int V_50 ;
F_16 () ;
for ( V_50 = 0 ; V_50 < F_15 ( V_35 -> V_52 , V_53 ) ; V_50 ++ ) {
if ( ! V_35 -> V_55 [ V_50 ] )
continue;
if ( V_59 )
F_22 ( V_35 ,
V_35 -> V_55 [ V_50 ] ,
V_46 ) ;
else
F_23 ( V_35 ,
V_35 -> V_55 [ V_50 ] ,
V_46 ) ;
}
F_20 () ;
return 0 ;
}
static int F_24 ( struct V_35 * V_35 )
{
struct V_60 * V_60 = F_25 ( V_35 -> V_52 ) ;
T_1 V_61 ;
V_61 = F_15 ( V_35 -> V_52 , V_53 ) ;
return F_26 ( V_60 ,
V_62 ,
& V_63 ,
V_35 , V_61 ,
false ) ;
}
static void F_27 ( struct V_35 * V_35 )
{
struct V_60 * V_60 = F_25 ( V_35 -> V_52 ) ;
F_28 ( V_60 , V_62 ) ;
}
int F_29 ( struct V_35 * V_35 )
{
struct V_60 * V_60 = F_25 ( V_35 -> V_52 ) ;
int V_6 ;
V_6 = F_30 ( V_60 ,
& V_64 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_24 ( V_35 ) ;
if ( V_6 )
goto V_65;
return 0 ;
V_65:
F_31 ( F_25 ( V_35 -> V_52 ) ) ;
return V_6 ;
}
void F_32 ( struct V_35 * V_35 )
{
struct V_60 * V_60 = F_25 ( V_35 -> V_52 ) ;
F_27 ( V_35 ) ;
F_31 ( V_60 ) ;
}
