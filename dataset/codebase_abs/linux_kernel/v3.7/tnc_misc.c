struct V_1 * F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
int V_4 , V_5 , V_6 = 0 ;
struct V_1 * V_7 ;
F_2 ( V_2 ) ;
if ( F_3 ( ! V_3 ) )
return V_2 ;
if ( F_3 ( V_3 == V_2 ) ) {
if ( V_3 -> V_4 == 0 )
return NULL ;
return F_4 ( V_2 , 0 ) ;
}
V_4 = V_3 -> V_4 ;
V_5 = V_3 -> V_5 ;
while ( 1 ) {
F_2 ( V_3 -> V_4 <= V_2 -> V_4 ) ;
while ( V_3 -> V_8 != V_2 && V_5 >= V_3 -> V_8 -> V_9 ) {
V_3 = V_3 -> V_8 ;
V_5 = V_3 -> V_5 ;
}
if ( F_3 ( V_3 -> V_8 == V_2 &&
V_5 >= V_3 -> V_8 -> V_9 ) ) {
V_4 -= 1 ;
if ( V_6 || V_4 < 0 )
return NULL ;
V_6 = 1 ;
V_5 = - 1 ;
V_3 = F_4 ( V_2 , 0 ) ;
F_2 ( V_3 ) ;
}
V_7 = F_4 ( V_3 -> V_8 , V_5 + 1 ) ;
if ( ! V_7 ) {
V_5 = V_3 -> V_8 -> V_9 ;
continue;
}
while ( V_7 -> V_4 != V_4 ) {
V_3 = V_7 ;
V_7 = F_4 ( V_7 , 0 ) ;
if ( ! V_7 ) {
V_5 = V_3 -> V_5 ;
break;
}
}
if ( V_7 ) {
F_2 ( V_7 -> V_4 >= 0 ) ;
return V_7 ;
}
}
}
int F_5 ( const struct V_10 * V_11 ,
const struct V_1 * V_3 ,
const union V_12 * V_13 , int * V_14 )
{
int V_15 = 0 , V_16 = V_3 -> V_9 , V_17 ( V_18 ) ;
int V_17 ( V_19 ) ;
const struct V_20 * V_21 = & V_3 -> V_22 [ 0 ] ;
F_2 ( V_16 > V_15 ) ;
while ( V_16 > V_15 ) {
V_18 = ( V_15 + V_16 ) >> 1 ;
V_19 = F_6 ( V_11 , V_13 , & V_21 [ V_18 ] . V_13 ) ;
if ( V_19 > 0 )
V_15 = V_18 + 1 ;
else if ( V_19 < 0 )
V_16 = V_18 ;
else {
* V_14 = V_18 ;
return 1 ;
}
}
* V_14 = V_16 - 1 ;
F_2 ( * V_14 >= - 1 && * V_14 < V_3 -> V_9 ) ;
if ( * V_14 == - 1 )
F_2 ( F_6 ( V_11 , V_13 , & V_21 [ 0 ] . V_13 ) < 0 ) ;
else
F_2 ( F_6 ( V_11 , V_13 , & V_21 [ * V_14 ] . V_13 ) > 0 ) ;
if ( * V_14 + 1 < V_3 -> V_9 )
F_2 ( F_6 ( V_11 , V_13 , & V_21 [ * V_14 + 1 ] . V_13 ) < 0 ) ;
return 0 ;
}
struct V_1 * F_7 ( struct V_1 * V_3 )
{
if ( F_3 ( ! V_3 ) )
return NULL ;
while ( V_3 -> V_4 > 0 ) {
struct V_1 * V_23 ;
V_23 = F_4 ( V_3 , 0 ) ;
if ( ! V_23 )
return V_3 ;
V_3 = V_23 ;
}
return V_3 ;
}
struct V_1 * F_8 ( struct V_1 * V_3 )
{
struct V_1 * V_7 ;
F_2 ( V_3 ) ;
if ( F_3 ( ! V_3 -> V_8 ) )
return NULL ;
V_7 = F_4 ( V_3 -> V_8 , V_3 -> V_5 + 1 ) ;
if ( ! V_7 )
return V_3 -> V_8 ;
return F_7 ( V_7 ) ;
}
long F_9 ( struct V_1 * V_3 )
{
struct V_1 * V_7 = F_7 ( V_3 ) ;
long V_24 = 0 ;
int V_14 ;
F_2 ( V_7 ) ;
while ( 1 ) {
for ( V_14 = 0 ; V_14 < V_7 -> V_9 ; V_14 ++ ) {
if ( ! V_7 -> V_22 [ V_14 ] . V_3 )
continue;
if ( V_7 -> V_4 > 0 &&
! F_10 ( V_7 -> V_22 [ V_14 ] . V_3 ) )
V_24 += 1 ;
F_11 () ;
F_12 ( V_7 -> V_22 [ V_14 ] . V_3 ) ;
}
if ( V_7 == V_3 ) {
if ( ! F_10 ( V_7 ) )
V_24 += 1 ;
F_12 ( V_7 ) ;
return V_24 ;
}
V_7 = F_8 ( V_7 ) ;
}
}
static int F_13 ( struct V_10 * V_11 , int V_25 , int V_26 , int V_27 ,
struct V_1 * V_3 )
{
int V_28 , V_29 , type , V_19 ;
struct V_30 * V_31 ;
V_31 = F_14 ( V_11 -> V_32 , V_33 ) ;
if ( ! V_31 )
return - V_34 ;
V_29 = F_15 ( V_11 , V_31 , V_35 , V_27 , V_25 , V_26 ) ;
if ( V_29 < 0 ) {
F_12 ( V_31 ) ;
return V_29 ;
}
V_3 -> V_9 = F_16 ( V_31 -> V_9 ) ;
V_3 -> V_4 = F_16 ( V_31 -> V_4 ) ;
F_17 ( L_1 ,
V_25 , V_26 , V_3 -> V_4 , V_3 -> V_9 ) ;
if ( V_3 -> V_9 > V_11 -> V_36 || V_3 -> V_4 > V_37 ) {
F_18 ( L_2 ,
V_11 -> V_36 , V_3 -> V_9 ) ;
F_18 ( L_3 ,
V_37 , V_3 -> V_4 ) ;
V_29 = 1 ;
goto V_38;
}
for ( V_28 = 0 ; V_28 < V_3 -> V_9 ; V_28 ++ ) {
const struct V_39 * V_40 = F_19 ( V_11 , V_31 , V_28 ) ;
struct V_20 * V_21 = & V_3 -> V_22 [ V_28 ] ;
F_20 ( V_11 , & V_40 -> V_13 , & V_21 -> V_13 ) ;
V_21 -> V_25 = F_21 ( V_40 -> V_25 ) ;
V_21 -> V_26 = F_21 ( V_40 -> V_26 ) ;
V_21 -> V_27 = F_21 ( V_40 -> V_27 ) ;
V_21 -> V_3 = NULL ;
if ( V_21 -> V_25 < V_11 -> V_41 ||
V_21 -> V_25 >= V_11 -> V_42 || V_21 -> V_26 < 0 ||
V_21 -> V_26 + V_21 -> V_27 > V_11 -> V_43 || V_21 -> V_26 & 7 ) {
F_18 ( L_4 , V_28 ) ;
V_29 = 2 ;
goto V_38;
}
switch ( F_22 ( V_11 , & V_21 -> V_13 ) ) {
case V_44 :
case V_45 :
case V_46 :
case V_47 :
break;
default:
F_18 ( L_5 ,
V_28 , F_22 ( V_11 , & V_21 -> V_13 ) ) ;
V_29 = 3 ;
goto V_38;
}
if ( V_3 -> V_4 )
continue;
type = F_22 ( V_11 , & V_21 -> V_13 ) ;
if ( V_11 -> V_48 [ type ] . V_49 == 0 ) {
if ( V_21 -> V_27 != V_11 -> V_48 [ type ] . V_27 ) {
F_18 ( L_6 ,
type , V_21 -> V_27 ) ;
F_18 ( L_7 , V_11 -> V_48 [ type ] . V_27 ) ;
V_29 = 4 ;
goto V_38;
}
} else if ( V_21 -> V_27 < V_11 -> V_48 [ type ] . V_50 ||
V_21 -> V_27 > V_11 -> V_48 [ type ] . V_49 ) {
F_18 ( L_6 ,
type , V_21 -> V_27 ) ;
F_18 ( L_8 ,
V_11 -> V_48 [ type ] . V_50 ,
V_11 -> V_48 [ type ] . V_49 ) ;
V_29 = 5 ;
goto V_38;
}
}
for ( V_28 = 0 ; V_28 < V_3 -> V_9 - 1 ; V_28 ++ ) {
const union V_12 * V_51 , * V_52 ;
V_51 = & V_3 -> V_22 [ V_28 ] . V_13 ;
V_52 = & V_3 -> V_22 [ V_28 + 1 ] . V_13 ;
V_19 = F_6 ( V_11 , V_51 , V_52 ) ;
if ( V_19 > 0 ) {
F_18 ( L_9 , V_28 , V_28 + 1 ) ;
V_29 = 6 ;
goto V_38;
} else if ( V_19 == 0 && ! F_23 ( V_11 , V_51 ) ) {
F_18 ( L_10 ,
V_28 , V_28 + 1 ) ;
V_29 = 7 ;
goto V_38;
}
}
F_12 ( V_31 ) ;
return 0 ;
V_38:
F_18 ( L_11 , V_25 , V_26 , V_29 ) ;
F_24 ( V_11 , V_31 ) ;
F_12 ( V_31 ) ;
return - V_53 ;
}
struct V_1 * F_25 ( struct V_10 * V_11 ,
struct V_20 * V_21 ,
struct V_1 * V_8 , int V_5 )
{
int V_29 ;
struct V_1 * V_3 ;
F_2 ( ! V_21 -> V_3 ) ;
V_3 = F_26 ( V_11 -> V_54 , V_33 ) ;
if ( ! V_3 )
return F_27 ( - V_34 ) ;
V_29 = F_13 ( V_11 , V_21 -> V_25 , V_21 -> V_26 , V_21 -> V_27 , V_3 ) ;
if ( V_29 )
goto V_55;
F_28 ( & V_11 -> V_56 ) ;
F_28 ( & V_57 ) ;
V_21 -> V_3 = V_3 ;
V_3 -> V_8 = V_8 ;
V_3 -> time = F_29 () ;
V_3 -> V_5 = V_5 ;
return V_3 ;
V_55:
F_12 ( V_3 ) ;
return F_27 ( V_29 ) ;
}
int F_30 ( struct V_10 * V_11 , struct V_20 * V_21 ,
void * V_58 )
{
union V_12 V_51 , * V_13 = & V_21 -> V_13 ;
int V_29 , type = F_22 ( V_11 , V_13 ) ;
struct V_59 * V_60 ;
V_60 = F_31 ( V_11 , V_21 -> V_25 ) ;
if ( V_60 )
V_29 = F_32 ( V_60 , V_58 , type , V_21 -> V_27 ,
V_21 -> V_25 , V_21 -> V_26 ) ;
else
V_29 = F_15 ( V_11 , V_58 , type , V_21 -> V_27 , V_21 -> V_25 ,
V_21 -> V_26 ) ;
if ( V_29 ) {
F_33 ( V_13 , L_12 ) ;
return V_29 ;
}
F_20 ( V_11 , V_58 + V_61 , & V_51 ) ;
if ( ! F_34 ( V_11 , V_13 , & V_51 ) ) {
F_18 ( L_13 ,
V_21 -> V_25 , V_21 -> V_26 ) ;
F_33 ( V_13 , L_14 ) ;
F_33 ( & V_51 , L_15 ) ;
F_24 ( V_11 , V_58 ) ;
return - V_53 ;
}
return 0 ;
}
