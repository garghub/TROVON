bool F_1 ( unsigned int V_1 , T_1 * V_2 )
{
unsigned int V_3 , V_4 , V_5 = F_2 ( & V_2 -> V_6 ) ;
for (; ; ) {
if ( ! V_5 )
return false ;
if ( F_3 ( V_5 == V_7 ) )
return true ;
V_4 = V_5 + V_1 ;
if ( V_4 < V_5 )
V_4 = V_7 ;
V_3 = F_4 ( & V_2 -> V_6 , V_5 , V_4 ) ;
if ( V_3 == V_5 )
break;
V_5 = V_3 ;
}
F_5 ( V_4 == V_7 , L_1 ) ;
return true ;
}
void F_6 ( unsigned int V_1 , T_1 * V_2 )
{
F_5 ( ! F_1 ( V_1 , V_2 ) , L_2 ) ;
}
bool F_7 ( T_1 * V_2 )
{
unsigned int V_3 , V_4 , V_5 = F_2 ( & V_2 -> V_6 ) ;
for (; ; ) {
V_4 = V_5 + 1 ;
if ( ! V_5 )
return false ;
if ( F_3 ( ! V_4 ) )
return true ;
V_3 = F_4 ( & V_2 -> V_6 , V_5 , V_4 ) ;
if ( V_3 == V_5 )
break;
V_5 = V_3 ;
}
F_5 ( V_4 == V_7 , L_1 ) ;
return true ;
}
void F_8 ( T_1 * V_2 )
{
F_5 ( ! F_7 ( V_2 ) , L_3 ) ;
}
bool F_9 ( unsigned int V_1 , T_1 * V_2 )
{
unsigned int V_3 , V_4 , V_5 = F_2 ( & V_2 -> V_6 ) ;
for (; ; ) {
if ( F_3 ( V_5 == V_7 ) )
return false ;
V_4 = V_5 - V_1 ;
if ( V_4 > V_5 ) {
F_5 ( V_4 > V_5 , L_4 ) ;
return false ;
}
V_3 = F_10 ( & V_2 -> V_6 , V_5 , V_4 ) ;
if ( V_3 == V_5 )
break;
V_5 = V_3 ;
}
return ! V_4 ;
}
bool F_11 ( T_1 * V_2 )
{
return F_9 ( 1 , V_2 ) ;
}
void F_12 ( T_1 * V_2 )
{
F_5 ( F_11 ( V_2 ) , L_5 ) ;
}
bool F_13 ( T_1 * V_2 )
{
return F_10 ( & V_2 -> V_6 , 1 , 0 ) == 1 ;
}
bool F_14 ( T_1 * V_2 )
{
unsigned int V_3 , V_4 , V_5 = F_2 ( & V_2 -> V_6 ) ;
for (; ; ) {
if ( F_3 ( V_5 == V_7 ) )
return true ;
if ( V_5 == 1 )
return false ;
V_4 = V_5 - 1 ;
if ( V_4 > V_5 ) {
F_5 ( V_4 > V_5 , L_4 ) ;
return true ;
}
V_3 = F_10 ( & V_2 -> V_6 , V_5 , V_4 ) ;
if ( V_3 == V_5 )
break;
V_5 = V_3 ;
}
return true ;
}
bool F_15 ( T_1 * V_2 , struct V_8 * V_9 )
{
if ( F_14 ( V_2 ) )
return false ;
F_16 ( V_9 ) ;
if ( ! F_11 ( V_2 ) ) {
F_17 ( V_9 ) ;
return false ;
}
return true ;
}
bool F_18 ( T_1 * V_2 , T_2 * V_9 )
{
if ( F_14 ( V_2 ) )
return false ;
F_19 ( V_9 ) ;
if ( ! F_11 ( V_2 ) ) {
F_20 ( V_9 ) ;
return false ;
}
return true ;
}
