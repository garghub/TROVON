static void F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
while ( ( V_3 = F_2 ( V_2 , NULL ) ) )
F_3 ( V_3 ) ;
}
static void F_4 ( struct V_4 * V_5 )
{
F_5 ( V_6 , V_7 ) ;
struct V_1 * V_3 = & V_5 -> V_3 ;
signed long V_8 ;
V_8 = V_9 ;
F_6 ( F_7 ( V_3 ) , & V_6 ) ;
while ( ! F_8 ( V_10 ) && V_8 ) {
int V_11 ;
V_11 = F_9 ( V_3 , & V_8 ,
! F_10 ( & V_5 -> V_12 ) ,
& V_6 ) ;
if ( V_11 )
break;
}
F_11 ( F_7 ( V_3 ) , & V_6 ) ;
}
static void F_12 ( struct V_4 * V_5 , long V_8 )
{
F_5 ( V_6 , V_7 ) ;
struct V_1 * V_3 = & V_5 -> V_3 ;
if ( ! V_8 )
return;
if ( ! F_13 ( & V_5 -> V_12 ) )
return;
V_5 -> V_13 = 1 ;
F_6 ( F_7 ( V_3 ) , & V_6 ) ;
while ( ! F_8 ( V_10 ) && V_8 ) {
int V_11 ;
V_11 = F_9 ( V_3 , & V_8 ,
! F_13 ( & V_5 -> V_12 ) ||
( V_3 -> V_14 == V_15 ) ||
( V_3 -> V_14 == V_16 ) ,
& V_6 ) ;
if ( V_11 )
break;
}
F_11 ( F_7 ( V_3 ) , & V_6 ) ;
V_5 -> V_13 = 0 ;
}
void F_14 ( struct V_4 * V_5 )
{
if ( V_5 -> V_13 )
V_5 -> V_3 . V_17 ( & V_5 -> V_3 ) ;
}
static int F_15 ( struct V_18 * V_12 )
{
V_12 -> V_19 . V_20 . V_21 = 1 ;
return F_16 ( V_12 ) ;
}
static int F_17 ( struct V_18 * V_12 )
{
if ( F_18 ( & V_12 -> V_22 ) )
V_12 -> V_19 . V_20 . V_23 = 1 ;
else
V_12 -> V_19 . V_20 . V_24 = 1 ;
return F_16 ( V_12 ) ;
}
static int F_19 ( struct V_18 * V_12 )
{
V_12 -> V_19 . V_20 . V_23 = 1 ;
return F_16 ( V_12 ) ;
}
void F_20 ( struct V_4 * V_5 )
{
struct V_25 * V_26 =
& V_5 -> V_12 . V_19 . V_20 ;
F_21 ( & V_5 -> V_3 ) ;
V_5 -> V_3 . V_14 = V_15 ;
if ( V_5 -> V_27 && V_5 -> V_27 -> V_3 ) {
V_5 -> V_27 -> V_3 -> V_14 = V_15 ;
V_5 -> V_27 -> V_3 -> V_17 ( V_5 -> V_27 -> V_3 ) ;
}
switch ( V_5 -> V_3 . V_28 ) {
case V_29 :
V_5 -> V_3 . V_28 = V_30 ;
break;
case V_31 :
case V_32 :
V_26 -> V_23 = 1 ;
F_22 ( V_5 -> V_27 ) ;
if ( ! F_23 ( & V_5 -> V_12 ) )
V_5 -> V_3 . V_28 = V_30 ;
else
V_5 -> V_3 . V_28 = V_33 ;
break;
case V_34 :
case V_35 :
if ( ! V_26 -> V_24 ) {
V_5 -> V_3 . V_28 = V_30 ;
V_26 -> V_23 = 1 ;
F_22 ( V_5 -> V_27 ) ;
} else {
V_5 -> V_3 . V_28 = V_33 ;
}
break;
case V_36 :
case V_37 :
if ( ! V_26 -> V_24 ) {
V_26 -> V_23 = 1 ;
F_22 ( V_5 -> V_27 ) ;
}
V_5 -> V_3 . V_28 = V_33 ;
break;
case V_38 :
case V_30 :
case V_33 :
break;
}
F_24 ( & V_5 -> V_3 , V_39 ) ;
F_25 ( & V_5 -> V_3 ) ;
V_5 -> V_3 . V_17 ( & V_5 -> V_3 ) ;
}
int F_26 ( struct V_4 * V_5 )
{
struct V_25 * V_26 =
& V_5 -> V_12 . V_19 . V_20 ;
long V_8 = V_40 ;
struct V_18 * V_12 = & V_5 -> V_12 ;
struct V_1 * V_3 = & V_5 -> V_3 ;
int V_41 ;
int V_11 = 0 ;
if ( F_27 ( V_3 , V_42 ) &&
! ( V_10 -> V_43 & V_44 ) )
V_8 = V_3 -> V_45 ;
V_46:
V_41 = V_3 -> V_28 ;
switch ( V_41 ) {
case V_29 :
V_3 -> V_28 = V_33 ;
if ( V_5 -> V_47 . V_48 )
F_28 ( & V_5 -> V_47 ) ;
F_29 ( V_3 ) ;
break;
case V_49 :
V_3 -> V_28 = V_33 ;
V_3 -> V_17 ( V_3 ) ;
if ( V_5 -> V_27 && V_5 -> V_27 -> V_3 ) {
V_11 = F_30 ( V_5 -> V_27 , V_50 ) ;
V_5 -> V_27 -> V_3 -> V_51 ( V_5 -> V_27 -> V_3 ) ;
}
F_31 ( V_3 ) ;
F_1 ( V_3 ) ;
F_28 ( & V_5 -> V_52 ) ;
F_32 ( V_3 ) ;
break;
case V_53 :
F_12 ( V_5 , V_8 ) ;
F_31 ( V_3 ) ;
F_33 ( & V_12 -> V_54 ) ;
F_32 ( V_3 ) ;
if ( V_3 -> V_28 == V_53 ) {
V_11 = F_17 ( V_12 ) ;
V_3 -> V_28 = V_34 ;
} else {
goto V_46;
}
break;
case V_37 :
if ( V_26 -> V_21 &&
! V_26 -> V_24 ) {
V_11 = F_17 ( V_12 ) ;
}
V_3 -> V_28 = V_33 ;
F_4 ( V_5 ) ;
break;
case V_31 :
case V_32 :
if ( ! F_23 ( V_12 ) )
F_12 ( V_5 , V_8 ) ;
F_31 ( V_3 ) ;
F_33 ( & V_12 -> V_54 ) ;
F_32 ( V_3 ) ;
if ( V_3 -> V_14 != V_15 ) {
V_11 = F_17 ( V_12 ) ;
if ( V_11 )
break;
}
if ( F_23 ( V_12 ) )
V_3 -> V_28 = V_33 ;
else
V_3 -> V_28 = V_38 ;
F_4 ( V_5 ) ;
break;
case V_34 :
case V_35 :
case V_38 :
break;
case V_36 :
F_33 ( & V_12 -> V_54 ) ;
F_19 ( V_12 ) ;
V_3 -> V_28 = V_33 ;
F_4 ( V_5 ) ;
break;
case V_30 :
case V_33 :
break;
}
if ( V_41 != V_3 -> V_28 )
V_3 -> V_17 ( & V_5 -> V_3 ) ;
return V_11 ;
}
static void F_34 ( struct V_4 * V_5 )
{
struct V_25 * V_26 =
& V_5 -> V_12 . V_19 . V_20 ;
struct V_1 * V_3 = & V_5 -> V_3 ;
switch ( V_3 -> V_28 ) {
case V_53 :
case V_37 :
case V_31 :
case V_32 :
F_19 ( & V_5 -> V_12 ) ;
V_3 -> V_28 = V_36 ;
break;
case V_34 :
case V_35 :
if ( V_26 -> V_21 &&
! V_26 -> V_24 ) {
F_19 ( & V_5 -> V_12 ) ;
V_3 -> V_28 = V_36 ;
} else {
V_3 -> V_28 = V_33 ;
}
break;
case V_38 :
case V_30 :
V_3 -> V_28 = V_33 ;
break;
case V_29 :
case V_36 :
break;
}
}
void F_35 ( struct V_4 * V_5 )
{
struct V_25 * V_55 =
& V_5 -> V_12 . V_56 . V_20 ;
struct V_1 * V_3 = & V_5 -> V_3 ;
int V_41 ;
V_3 -> V_57 |= V_58 ;
if ( V_5 -> V_27 && V_5 -> V_27 -> V_3 )
V_5 -> V_27 -> V_3 -> V_57 |= V_58 ;
F_24 ( & V_5 -> V_3 , V_59 ) ;
V_41 = V_3 -> V_28 ;
if ( V_55 -> V_23 ) {
F_34 ( V_5 ) ;
goto V_60;
}
switch ( V_3 -> V_28 ) {
case V_29 :
if ( F_18 ( & V_5 -> V_12 . V_22 ) ||
( V_55 -> V_21 &&
! V_55 -> V_24 ) )
V_3 -> V_28 = V_31 ;
else
V_3 -> V_28 = V_33 ;
break;
case V_53 :
V_3 -> V_28 = V_31 ;
break;
case V_34 :
if ( V_55 -> V_21 )
V_3 -> V_28 = V_35 ;
case V_35 :
case V_38 :
if ( ! F_23 ( & V_5 -> V_12 ) )
break;
if ( F_27 ( V_3 , V_39 ) &&
( V_3 -> V_57 == V_61 ) ) {
V_3 -> V_28 = V_33 ;
} else {
V_3 -> V_28 = V_37 ;
}
break;
case V_31 :
case V_32 :
case V_37 :
case V_30 :
case V_36 :
case V_33 :
break;
}
V_60:
if ( V_41 != V_3 -> V_28 )
V_3 -> V_17 ( V_3 ) ;
V_3 -> V_51 ( V_3 ) ;
V_3 -> V_62 ( V_3 ) ;
if ( ( V_3 -> V_28 == V_33 ) &&
( F_27 ( V_3 , V_39 ) || ( V_41 == V_29 ) ) ) {
F_36 ( & V_5 -> V_12 ) ;
F_37 ( & V_5 -> V_63 ,
V_64 ) ;
}
}
void F_38 ( struct V_65 * V_66 )
{
struct V_4 * V_5 = F_39 ( F_40 ( V_66 ) ,
struct V_4 ,
V_63 ) ;
V_5 -> V_3 . V_67 -> V_68 ( & V_5 -> V_3 ) ;
F_29 ( & V_5 -> V_3 ) ;
}
int F_41 ( struct V_4 * V_5 )
{
struct V_18 * V_12 = & V_5 -> V_12 ;
long V_8 = V_40 ;
struct V_1 * V_3 = & V_5 -> V_3 ;
int V_41 ;
int V_11 = 0 ;
if ( F_27 ( V_3 , V_42 ) )
V_8 = V_3 -> V_45 ;
V_46:
V_41 = V_3 -> V_28 ;
switch ( V_41 ) {
case V_53 :
F_12 ( V_5 , V_8 ) ;
F_31 ( V_3 ) ;
F_33 ( & V_12 -> V_54 ) ;
F_32 ( V_3 ) ;
V_11 = F_15 ( V_12 ) ;
if ( V_3 -> V_28 == V_53 )
V_3 -> V_28 = V_34 ;
else
goto V_46;
break;
case V_31 :
if ( ! F_23 ( V_12 ) )
F_12 ( V_5 , V_8 ) ;
F_31 ( V_3 ) ;
F_33 ( & V_12 -> V_54 ) ;
F_32 ( V_3 ) ;
V_11 = F_15 ( V_12 ) ;
V_3 -> V_28 = V_32 ;
break;
case V_32 :
case V_38 :
case V_34 :
case V_35 :
case V_37 :
case V_36 :
case V_30 :
break;
}
if ( V_41 != V_3 -> V_28 )
V_3 -> V_17 ( & V_5 -> V_3 ) ;
return V_11 ;
}
